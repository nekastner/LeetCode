int climbStairs(const int n) {

    /* Walk the steps down from above
     * and add the possibilities from the last two steps together
     * to get the current possibilities
     * until you reach the bottom.
     * Because you can only come from one or two steps from above,
     * and you just take their results with you.
     */

    // no calculation required for first two steps
    if (n <= 2) {
        return n;
    }

    // calculate result for current step from results of the last two steps
    int results[3] = {1, 2, 0}; // previous-previous step, previous step, current step
    for (int i = 3; i <= n; i++) {
        // calculate possibilities of current step
        results[2] = results[0] + results[1];
        // shift possibilities for the last two steps (because we go further and the last two steps are not the same anymore)
        results[0] = results[1];
        results[1] = results[2];
    }

    return results[2];
}