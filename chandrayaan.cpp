#include <iostream>

class Chandrayaan3 {
public:
    Chandrayaan3(int x, int y, int z, char direction) 
        : x(x), y(y), z(z), direction(direction) {}

    void move(char command) {
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
    }

    void turn(char command) {
        if (command == 'l') {
            if (direction == 'N') direction = 'W';
            else if (direction == 'S') direction = 'E';
            else if (direction == 'E') direction = 'N';
            else if (direction == 'W') direction = 'S';
        }
        else if (command == 'r') {
            if (direction == 'N') direction = 'E';
            else if (direction == 'S') direction = 'W';
            else if (direction == 'E') direction = 'S';
            else if (direction == 'W') direction = 'N';
        }
        else if (command == 'u') {
            if (direction == 'N' || direction == 'S') direction = 'U';
            else if (direction == 'U') {
                direction = 'S';
                z--;
            }
            else if (direction == 'D') {
                direction = 'N';
                z++;
            }
        }
    }

    void executeCommands(const std::string& commands) {
        for (char command : commands) {
            if (command == 'f' || command == 'b') {
                move(command);
            }
            else if (command == 'l' || command == 'r' || command == 'u') {
                turn(command);
            }
        }
    }

    void getPosition(int& x, int& y, int& z) const {
        x = this->x;
        y = this->y;
        z = this->z;
    }

    char getDirection() const {
        return direction;
    }

private:
    int x, y, z;
    char direction;
};

int main() {
    int initialX = 0, initialY = 0, initialZ = 0;
    char initialDirection = 'N';
    std::string commands = "frubl";

    Chandrayaan3 chandrayaan(initialX, initialY, initialZ, initialDirection);
    chandrayaan.executeCommands(commands);

    int finalX, finalY, finalZ;
    char finalDirection;
    chandrayaan.getPosition(finalX, finalY, finalZ);
    finalDirection = chandrayaan.getDirection();

    std::cout << "Final Position: (" << finalX << ", " << finalY << ", " << finalZ << ")\n";
    std::cout << "Final Direction: " << finalDirection << "\n";

    return 0;
}
