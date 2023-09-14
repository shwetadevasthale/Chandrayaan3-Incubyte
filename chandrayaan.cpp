#include <iostream>
using namespace std;

class Chandrayaan3
{
private:
    int x, y, z;
    char direction;

public:
    char prev = '0';

    Chandrayaan3(int x, int y, int z, char direction)
        : x(x), y(y), z(z), direction(direction) {}

    void move(char command)
    {
        if (command == 'f')
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
        else if (command == 'b')
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
    }

    void turn(char command)
    {
        if (command == 'l')
        {
            prev = direction;
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
            if (direction == 'N' or direction == 'S' or direction == 'E' or direction == 'W')
                direction = 'U';
            else if (direction == 'U')
                direction = 'S';
            else if (direction == 'D')
                direction = 'N';
        }
        else
        {
            if (direction == 'N' or direction == 'S' or direction == 'E' or direction == 'W')
                direction = 'D';
            else if (direction == 'U')
                direction = 'N';
            else if (direction == 'D')
                direction = 'S';
        }
    }

    void executeCommands(const string &commands)
    {
        for (char command : commands)
        {
            if (command == 'f' || command == 'b')
            {
                move(command);
            }
            else if (command == 'l' || command == 'r' || command == 'u' || command=='d')
            {
                turn(command);
            }
        }
    }

    void getPosition(int &x, int &y, int &z) const
    {
        x = this->x;
        y = this->y;
        z = this->z;
    }

    char getDirection() const
    {
        return direction;
    }
};


int main()
{
    int initialX = 0, initialY = 0, initialZ = 0;
    char initialDirection = 'N';
    char commands[] = {'f','r','u','b','l'};
    
    Chandrayaan3 chandrayaan(initialX, initialY, initialZ, initialDirection);
    chandrayaan.executeCommands(commands);

    int finalX, finalY, finalZ;
    char finalDirection;
    chandrayaan.getPosition(finalX, finalY, finalZ);
    finalDirection = chandrayaan.getDirection();

    cout << "Final Position: (" << finalX << ", " << finalY << ", " << finalZ << ")\n";
    cout << "Final Direction: " << finalDirection << "\n";

    return 0;
}
