#include <iostream>
using namespace std;

int main() {
    int x = 0, y = 0, z = 0;
    
    char d = 'N';
    char commands[] = {'f','r','u','b','l'};
    char prev = '0';

    for (char command : commands) {
            
        if (command == 'f') {
            if (d == 'N') y++;
            else if (d == 'S') y--;
            else if (d == 'E') x++;
            else if (d == 'W') x--;
            else if (d == 'U') z++;
            else if (d == 'D') z--;
        }
        else if (command == 'b') {
            if (d == 'N') y--;
            else if (d == 'S') y++;
            else if (d == 'E') x--;
            else if (d == 'W') x++;
            else if (d == 'U') z--;
            else if (d == 'D') z++;
        }
        else if (command == 'l') {
            prev = d;
            if (d == 'N') d = 'W';
            else if (d == 'S') d = 'E';
            else if (d == 'E') d = 'N';
            else if (d == 'W') d = 'S';
            else {
                if(prev=='E')
                    d = 'N';
                else if(prev=='N')
                    d = 'W';
                else if(prev=='W') 
                    d = 'S';
                else if(prev=='S')
                    d = 'E';
            }
        }
        else if (command == 'r') {
            prev = d;
            if (d == 'N') d = 'E';
            else if (d == 'S') d = 'W';
            else if (d == 'E') d = 'S';
            else if (d == 'W') d = 'N';
            else {
                if(prev=='E')
                    d = 'S';
                else if(prev=='N')
                    d = 'E';
                else if(prev=='W') 
                    d = 'N';
                else if(prev=='S')
                    d = 'W';
            }
        }
        else if (command == 'u'){
            if (d=='N' or d=='S' or d=='E' or d=='W')
                d = 'U';
            else if(d=='U') 
                d = 'S';
            else if(d=='D')
                d = 'N';
        }
        else{
            if (d=='N' or d=='S' or d=='E' or d=='W')
                d = 'D';
            else if(d=='U') 
                d = 'N';
            else if(d=='D')
                d = 'S';
        }
    }

    std::cout << "Final Position: (" << x << ", " << y << ", " << z << ")\n";
    std::cout << "Final Direction: " << d << "\n";

    return 0;
}



