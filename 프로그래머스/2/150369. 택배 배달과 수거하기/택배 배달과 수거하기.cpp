#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
현재 pos부터 가까운 집 방향으로 이동하면서
boxes의 물량을 최대 cap개 처리한다.

boxes가 deliveries이면 배달 처리,
boxes가 pickups이면 수거 처리이다.
*/
void processBoxes(int cap, int& pos, vector<int>& boxes)
{
    int remainCapacity = cap;

    while (pos >= 0 && remainCapacity > 0)
    {
        // 현재 집에 처리할 물량이 없다면 가까운 집으로 이동
        if (boxes[pos] == 0)
        {
            pos--;
            continue;
        }

        // 이번 운행에서 처리할 수 있는 양
        int amount = min(remainCapacity, boxes[pos]);

        boxes[pos] -= amount;
        remainCapacity -= amount;

        // 현재 집의 물량을 모두 처리했다면 다음 집으로 이동
        if (boxes[pos] == 0)
        {
            pos--;
        }
    }

    // 현재 위치부터 연속된 0 구간을 건너뛴다.
    while (pos >= 0 && boxes[pos] == 0)
    {
        pos--;
    }
}

/*
트럭이 한 번 왕복하는 함수
*/
void move(int cap,int& deliveryPos,int& pickupPos,vector<int>& deliveries,
          vector<int>& pickups,long long& answer)
{
    // 배달 또는 수거가 남아 있는 가장 먼 집
    int farthest = max(deliveryPos, pickupPos);

    // 가장 먼 집까지 갔다가 창고로 복귀
    answer += 2LL * (farthest + 1);

    /*
    한 번의 운행에서

    배달은 최대 cap개,
    수거도 최대 cap개

    각각 처리할 수 있다.
    */
    processBoxes(cap, deliveryPos, deliveries);
    processBoxes(cap, pickupPos, pickups);
}

long long solution(int cap,int n,vector<int> deliveries,vector<int> pickups)
{
    long long answer = 0;

    int deliveryPos = n - 1;
    int pickupPos = n - 1;

    // 처음부터 물량이 0인 먼 집들을 건너뛴다.
    while (deliveryPos >= 0 && deliveries[deliveryPos] == 0)
    {
        deliveryPos--;
    }

    while (pickupPos >= 0 && pickups[pickupPos] == 0)
    {
        pickupPos--;
    }

    // 배달이나 수거 중 하나라도 남아 있다면 운행
    while (deliveryPos >= 0 || pickupPos >= 0)
    {
        move(cap,deliveryPos,pickupPos,deliveries,pickups,answer);
    }

    return answer;
}