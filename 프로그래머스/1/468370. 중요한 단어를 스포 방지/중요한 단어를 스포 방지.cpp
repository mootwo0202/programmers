#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;

    int s_p = 0;
    vector<int> s_w;

    int len = message.size();
    vector<string> w;

    int wcount = 0;
    int p = 0;

    for (int i = 0; i < len; ++i)
    {
        if (message[i] == ' ')
        {
            int wordEnd = i - 1;

            w.push_back(message.substr(p, i - p));

            while (s_p < spoiler_ranges.size() &&
                   spoiler_ranges[s_p][1] < p)
            {
                s_p++;
            }

            // 단어 [p, wordEnd]와 스포일러 범위가 겹치는지 검사
            if (s_p < spoiler_ranges.size() &&
                p <= spoiler_ranges[s_p][1] &&
                spoiler_ranges[s_p][0] <= wordEnd)
            {
                s_w.push_back(wcount);
            }

            wcount++;
            p = i + 1;
        }
    }

    // 마지막 단어
    int wordEnd = len - 1;

    w.push_back(message.substr(p, len - p));

    while (s_p < spoiler_ranges.size() &&
           spoiler_ranges[s_p][1] < p)
    {
        s_p++;
    }

    if (s_p < spoiler_ranges.size() &&
        p <= spoiler_ranges[s_p][1] &&
        spoiler_ranges[s_p][0] <= wordEnd)
    {
        s_w.push_back(wcount);
    }

    vector<string> w_spo = w;

    // 모든 스포일러 단어를 임시 제거
    for (int j = 0; j < s_w.size(); ++j)
    {
        w_spo[s_w[j]] = " ";
    }

    // 스포일러 단어를 공개 순서대로 검사
    for (int k = 0; k < s_w.size(); ++k)
    {
        if (find(w_spo.begin(), w_spo.end(), w[s_w[k]]) == w_spo.end())
        {
            answer++;
        }

        // 공개된 단어를 다시 넣어서 이후 중복 검사에 사용
        w_spo[s_w[k]] = w[s_w[k]];
    }

    return answer;
}