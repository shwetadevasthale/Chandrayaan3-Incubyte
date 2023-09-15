#include <iostream>
#include <stdexcept> // Include for exception handling
using namespace std;

class Chandrayaan3
{
private:
    int x, y, z;
    char direction;
    char prev = '0'; // Previous direction to handle 'l' and 'r' commands

public:
    Chandrayaan3(int x, int y, int z, char direction)
        : x(x), y(y), z(z), direction(direction) {}

    // Move the spacecraft forward or backward
    void move(char command)
    {
        if (command == 'f')
        {
            // Check boundaries before moving forward
            if (!isValidMove(x, y, z, direction, 1))
            {
                throw invalid_argument("Invalid move command.");
            }
            moveForward();
        }
        else if (command == 'b')
        {
            // Check boundaries before moving backward
            if (!isValidMove(x, y, z, direction, -1))
            {
                throw invalid_argument("Invalid move command.");
            }
            moveBackward();
        }
    }

    // Turn the spacecraft left or right
    void turn(char command)
    {
        if (command == 'l')
        {
            prev = direction;
            // Rotate left 90 degrees
            if (direction == 'N')
                direction = 'W';
            else if (direction == 'S')
                direction = 'E';
            else if (direction == 'E')
                direction = 'N';
            else if (direction == 'W')
                direction = 'S';
            else
            {
                // Handle 'l' command when spacecraft is tilted (U or D)
                if (prev == 'E')
                    direction = 'N';
                else if (prev == 'N')
                    direction = 'W';
                else if (prev == 'W')
                    direction = 'S';
                else if (prev == 'S')
                    direction = 'E';
            }
        }
        else if (command == 'r')
        {
            prev = direction;
            // Rotate right 90 degrees
            if (direction == 'N')
                direction = 'E';
            else if (direction == 'S')
                direction = 'W';
            else if (direction == 'E')
                direction = 'S';
            else if (direction == 'W')
                direction = 'N';
            else
            {
                // Handle 'r' command when spacecraft is tilted (U or D)
                if (prev == 'E')
                    direction = 'S';
                else if (prev == 'N')
                    direction = 'E';
                else if (prev == 'W')
                    direction = 'N';
                else if (prev == 'S')
                    direction = 'W';
            }
        }
        else if (command == 'u')
        {
            // Check boundaries before tilting up
            if (!isValidTilt(direction, 'U'))
            {
                throw invalid_argument("Invalid tilt up command.");
            }
            tiltUp();
        }
        else
        {
            // Check boundaries before tilting down
            if (!isValidTilt(direction, 'D'))
            {
                throw invalid_argument("Invalid tilt down command.");
            }
            tiltDown();
        }
    }

    // Execute a sequence of commands
    void executeCommands(const char commands[], int numCommands)
    {
        for (int i = 0; i < numCommands; i++)
        {
            char command = commands[i];
            if (command == 'f' || command == 'b')
            {
                move(command);
            }
            else if (command == 'l' || command == 'r' || command == 'u' || command == 'd')
            {
                turn(command);
            }
            else
            {
                throw invalid_argument("Invalid command.");
            }
        }
    }

    // Get the final position of the spacecraft
    void getPosition(int &finalX, int &finalY, int &finalZ) const
    {
        finalX = x;
        finalY = y;
        finalZ = z;
    }

    // Get the final direction of the spacecraft
    char getDirection() const
    {
        return direction;
    }

private:
    void moveForward()
    {
        if (direction == 'N')
            y++;
        else if (direction == 'S')
            y--;
        else if (direction == 'E')
            x++;
        else if (direction == 'W')
            x--;
        else if (direction == 'U')
            z++;
        else if (direction == 'D')
            z--;
    }

    void moveBackward()
    {
        if (direction == 'N')
            y--;
        else if (direction == 'S')
            y++;
        else if (direction == 'E')
            x--;
        else if (direction == 'W')
            x++;
        else if (direction == 'U')
            z--;
        else if (direction == 'D')
            z++;
    }

    void tiltUp()
    {
        if (direction == 'N' || direction == 'S' || direction == 'E' || direction == 'W')
            direction = 'U';
        else if (direction == 'U')
            direction = 'S';
        else if (direction == 'D')
            direction = 'N';
    }

    void tiltDown()
    {
        if (direction == 'N' || direction == 'S' || direction == 'E' || direction == 'W')
            direction = 'D';
        else if (direction == 'D')
            direction = 'S';
        else if (direction == 'U')
            direction = 'N';
    }

    // Check if the move is valid within boundaries
    bool isValidMove(int x, int y, int z, char direction, int step)
    {
        // Check boundaries for x, y, and z
        // You can define the boundaries according to your requirements
        // For example, if x, y, and z must be within [-10, 10]:
        if (x + step < -10 || x + step > 10 || y + step < -10 || y + step > 10 || z + step < -10 || z + step > 10)
        {
            return false;
        }
        return true;
    }

    // Check if the tilt command is valid
    bool isValidTilt(char currentDirection, char tiltDirection)
    {
        // Check if the spacecraft is already tilted (U or D)
        if (currentDirection == 'U' || currentDirection == 'D')
        {
            // If it's already tilted, a new tilt command in the same direction is not valid
            return false;
        }

        // Check if the tilt direction is 'U' or 'D'
        if (tiltDirection != 'U' && tiltDirection != 'D')
        {
            // Invalid tilt direction
            return false;
        }
        // If none of the above conditions are met, the tilt command is valid
        return true;
    }
};

int main()
{
    int initialX = 0, initialY = 0, initialZ = 0;
    char initialDirection = 'N';
    char commands[] = {'f', 'r', 'u', 'b', 'l'};
    int numCommands = sizeof(commands) / sizeof(commands[0]);

    Chandrayaan3 chandrayaan(initialX, initialY, initialZ, initialDirection);
    chandrayaan.executeCommands(commands, numCommands);

    int finalX, finalY, finalZ;
    char finalDirection;
    chandrayaan.getPosition(finalX, finalY, finalZ);
    finalDirection = chandrayaan.getDirection();

    cout << "Final Position: (" << finalX << ", " << finalY << ", " << finalZ << ")\n";
    cout << "Final Direction: " << finalDirection << "\n";

    return 0;
}