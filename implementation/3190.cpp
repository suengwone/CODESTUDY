// 뱀

#include <iostream>
#include <deque>
#include <vector>
#include <map>

using namespace std;

class point
{
public:
    int x;
    int y;

    point()
    {
        this->x = 0;
        this->y = 0;
    }

    point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    bool operator==(point& compare)
    {
        return this->x == compare.x && this->y == compare.y;
    }

};

point operator+(point& point1, point& point2)
{
    return point(point1.x + point2.x, point1.y + point2.y);
}


point directions[] = { point(0,1), point(1,0), point(0,-1), point(-1,0) };

vector<point> applePosList;
point curDirection;
deque<point> snake;
bool isEnd = false;
int N;

int move(int count)
{
    for(int i=0; i<count; i++)
    {
        point movePos = curDirection + snake.front();
        
        if(movePos.x >= N || movePos.x < 0 || movePos.y >= N || movePos.y < 0)
        {
            isEnd = true;
            return i + 1;
        }
        else
        {
            for(auto iter = snake.begin(); iter != snake.end(); iter++)
            {
                if(*iter == movePos)
                {
                    isEnd = true;
                    return i + 1;
                }
            }
        }

        snake.push_front(movePos);

        bool isEat = false;
        for(auto iter = applePosList.begin(); iter != applePosList.end(); iter++)
        {
            if(*iter == movePos)
            {
                applePosList.erase(iter);
                isEat = true;
                break;
            }
        }

        if(isEat == false)
            snake.pop_back();
    }

    return count;
}

int main()
{
    int K, L;

    cin >> N >> K;

    applePosList.resize(K);

    // Get Apple Position
    for(int i=0; i<K; i++)
    {
        point applePos;
        cin >> applePos.x >> applePos.y;

        applePos.x -= 1;
        applePos.y -= 1;
        applePosList[i] = applePos;
    }

    cin >> L;

    snake.push_back(point(0, 0));

    int currentTime = 0;
    int directionIdx = 0;
    
    curDirection = directions[directionIdx];

    for(int i=0; i<L + 1; i++)
    {
        if(i < L)
        {
            int time;
            char direction;

            cin >> time >> direction;
            currentTime += move(time - currentTime);
            
            if(isEnd == true)
                break;

            if(direction == 'D')
            {
                directionIdx += 1;
                directionIdx %= 4;

                curDirection = directions[directionIdx];
            }
            else
            {
                directionIdx -= 1;
                directionIdx += 4;
                directionIdx %= 4;

                curDirection = directions[directionIdx];
            }
        }
        else
            currentTime += move(N);
    }

    cout << currentTime << '\n';

    return 0;
}
