#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumEnergy(std::vector<int>& energy, int k) {
        int n = energy.size();
        int max_energy = INT_MIN;

        // Iterate backward from the end of the array.
        // For each element energy[i], add the energy from the next jump (i + k).
        // This way, energy[i] will store the total energy for a path starting at i.
        for (int i = n - 1; i >= 0; --i) {
            // Check if a valid next jump exists within the array bounds
            if (i + k < n) {
                energy[i] += energy[i + k];
            }
            // Update the overall maximum energy found so far
            max_energy = std::max(max_energy, energy[i]);
        }

        return max_energy;
    }
};