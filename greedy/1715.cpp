// 카드 정렬하기

#include <iostream>
#include <queue>

using namespace std;

class Cards
{
    int shuffleCnt;
    priority_queue<int, vector<int>, greater<int> > cardList;

    public: void SetCard(int _value)
    {
        this->cardList.push(_value);
    }

    public: Cards()
    {
        this->shuffleCnt = 0;
    }

    public: int CalculateShuffleCnt()
    {
        int tempNum_1, tempNum_2, sum;

        while(cardList.size() != 1)
        {
            tempNum_1 = this->cardList.top();
            this->cardList.pop();

            tempNum_2 = this->cardList.top();
            this->cardList.pop();

            sum = tempNum_1 + tempNum_2;

            this->shuffleCnt += sum;

            this->cardList.push(sum);
        }

        return this->shuffleCnt;
    }
};


int main()
{
    int N, tempNum;
    
    cin >> N;

    Cards _cards = Cards();
    
    for(int i=0; i<N; i++)
    {
        cin >> tempNum;
        _cards.SetCard(tempNum);
    }

    cout << _cards.CalculateShuffleCnt() << '\n';

    return 0;
}
