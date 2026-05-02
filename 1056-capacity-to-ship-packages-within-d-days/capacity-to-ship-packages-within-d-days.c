int canShip(int* weights, int n, int days, int cap) {
    int d = 1;      // start with day 1
    int load = 0;

    for(int i = 0; i < n; i++) {
        if(load + weights[i] > cap) {
            d++;                // new day
            load = weights[i];
        } else {
            load += weights[i];
        }
    }

    return d <= days;
}

int shipWithinDays(int* weights, int weightsSize, int days) {

    int low = 0, high = 0;

    // initialize bounds
    for(int i = 0; i < weightsSize; i++) {
        if(weights[i] > low)
            low = weights[i];   // max weight
        high += weights[i];     // sum
    }

    int ans = high;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(canShip(weights, weightsSize, days, mid)) {
            ans = mid;         // possible
            high = mid - 1;    // try smaller capacity
        } else {
            low = mid + 1;
        }
    }

    return ans;
}