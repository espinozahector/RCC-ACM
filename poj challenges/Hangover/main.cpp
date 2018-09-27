#include <iostream> // Input and output
using namespace std;

// http://poj.org/problem?id=1003

int main(int argc, char** argv) {
    float L; // The length of the over hang
    int N = 0; // The estimated number of cards to achieve the overhang
    float sum = 0; // The running sum for the overhang length
    
    cin >> L; // Read in the length
    
    // Loop for every input of L
    while (L > 0.0f) { // If 0 is entered, then end the program
        // Reset N and sum to 0
        N = 0;
        sum = 0;

        // Loop through every number of cards
        do {
            N++; // Increment the number of cards
            
            sum += 1.0f / (N + 1.0f); // Add one more card to the running length
            // We use 1.0f which specifies that the number is a float. This avoids integer division, which is truncated.
            
        } while (sum < L); // Once sum is greater than or equal to L we know we've found the answer
        
        cout << N << " card(s)" << endl; // Output the result
        
        cin >> L; // Read in the next length
    }
    
    return 0;
}