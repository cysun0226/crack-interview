/**
* Leetcode 621. Task Scheduler
* https://leetcode.com/problems/task-scheduler/
*/

#include <vector>
#include <map>
using namespace std;

class Solution {
private:
    typedef map<char, int> M;
    static bool value_comparer(M::value_type &i1, M::value_type &i2) {
        return i1.second < i2.second; 
    }
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> task_count;
        for (char t: tasks) {
            if (task_count.find(t) == task_count.end())
                task_count[t] = 1;
            else
                task_count[t]++;
        }

        // the task that requires the most execution time
        M::iterator max_iter = max_element(task_count.begin(), task_count.end(), value_comparer);
        int max_intervals = max_iter->second - 1;
        int idle_slots = n * max_intervals;

        for (const auto & [key, value] : task_count) {
            if (key == max_iter->first) continue;

            idle_slots -= min(value, max_intervals);
        }

        return (idle_slots > 0)? idle_slots + tasks.size() : tasks.size();
    }
};