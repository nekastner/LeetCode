#include <stdbool.h>
#include <stdint.h>

struct stripe_mem {
	// 81 bits required (using 88 here)
	uint64_t v1;
	uint16_t v2;
	uint8_t v3;
};

bool stripe_mem_get_at(const struct stripe_mem *stripe_mem, const uint8_t index)
{
	// return stripe mem AND the indexed bit (if indexed bit is true in stripe mem, return will be greater than zero)
	if (index >= 81) return false;
	if (index < 64) return stripe_mem->v1 & ((uint64_t)1 << index);
	if (index < 80) return stripe_mem->v2 & ((uint16_t)1 << (index - 64));
	return stripe_mem->v3 & ((uint8_t)1 << (index - 80));
}

void stripe_mem_set_at(struct stripe_mem *stripe_mem, const uint8_t index)
{
	// stripe mem OR the indexed bit (indexed bit always gets set in stripe mem)
	if (index >= 81) return;
	if (index < 64) stripe_mem->v1 |= (uint64_t)1 << index;
	else if (index < 80) stripe_mem->v2 |= (uint16_t)1 << (index - 64);
	else stripe_mem->v3 |= (uint8_t)1 << (index - 80);
}

void stripe_mem_unset_at(struct stripe_mem *stripe_mem, const uint8_t index)
{
	// stripe mem AND everything but the indexed bit (indexed bit always gets unset in stripe mem)
	if (index >= 81) return;
	if (index < 64) stripe_mem->v1 &= ~((uint64_t)1 << index);
	else if (index < 80) stripe_mem->v2 &= ~((uint16_t)1 << (index - 64));
	else stripe_mem->v3 &= ~((uint8_t)1 << (index - 80));
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
	struct stripe_mem rows;
	struct stripe_mem cols;
	struct stripe_mem boxes;

	for (int i = 0; i < 9; i++) // rows
	{
		for (int j = 0; j < 9; j++) // columns
		{
			if (board[i][j] == '.') continue;

			// calculate indexes from value
			const uint8_t value_index = board[i][j] - 49; // convert char to index (e.g. '1' -> 0)
			const uint8_t row_index = i * 9 + value_index; // which row
			const uint8_t col_index = j * 9 + value_index; // which col
			const uint8_t box_index = ((i / 3) * 3 + (j / 3)) * 9 + value_index; // which box

			// if value already exists in same row, column or box, the sudoku is invalid
			if (stripe_mem_get_at(&rows, row_index) ||
				stripe_mem_get_at(&cols, col_index) ||
				stripe_mem_get_at(&boxes, box_index)) return false;

			//  save value
			stripe_mem_set_at(&rows, row_index);
			stripe_mem_set_at(&cols, col_index);
			stripe_mem_set_at(&boxes, box_index);
		}
	}

	return true; // no failure found, so the sudoku must be valid
}
