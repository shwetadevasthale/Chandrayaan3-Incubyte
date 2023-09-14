#include<iostream>
using namespace std;

int main() {
    int x = 0, y = 0, z = 0;
    
    char direction = 'N';
    char commands[] = {'f','r','u','b','l'};
    char prev = '0';

    for (char command : commands) {
            
        if (command == 'f') {
            if (direction == 'N') y++;
            else if (direction == 'S') y--;
            else if (direction == 'E') x++;
            else if (direction == 'W') x--;
            else if (direction == 'U') z++;
            else if (direction == 'D') z--;
        }
        else if (command == 'b') {
            if (direction == 'N') y--;
            else if (direction == 'S') y++;
            else if (direction == 'E') x--;
            else if (direction == 'W') x++;
            else if (direction == 'U') z--;
            else if (direction == 'D') z++;
        }
        else if (command == 'l') {
            prev = direction;
            if (direction == 'N') direction = 'W';
            else if (direction == 'S') direction = 'E';
            else if (direction == 'E') direction = 'N';
            else if (direction == 'W') direction = 'S';
            else {
                if(prev=='E')
                    direction = 'N';
                else if(prev=='N')
                    direction = 'W';
                else if(prev=='W') 
                    direction = 'S';
                else if(prev=='S')
                    direction = 'E';
            }
        }
        else if (command == 'r') {
            prev = direction;
            if (direction == 'N') direction = 'E';
            else if (direction == 'S') direction = 'W';
            else if (direction == 'E') direction = 'S';
            else if (direction == 'W') direction = 'N';
            else {
                if(prev=='E')
                    direction = 'S';
                else if(prev=='N')
                    direction = 'E';
                else if(prev=='W') 
                    direction = 'N';
                else if(prev=='S')
                    direction = 'W';
            }
        }
        else if (command == 'u'){
            if (direction=='N' or direction=='S' or direction=='E' or direction=='W')
                direction = 'U';
            else if(direction=='U') 
                direction = 'S';
            else if(direction=='D')
                direction = 'N';
        }
        else{
            if (direction=='N' or direction=='S' or direction=='E' or direction=='W')
                direction = 'D';
            else if(direction=='U') 
                direction = 'N';
            else if(direction=='D')
                direction = 'S';
        }
    }

    cout << "Final Position: (" << x << ", " << y << ", " << z << ")\n";
    cout << "Final direction: " << direction << "\n";

    return 0;
}



