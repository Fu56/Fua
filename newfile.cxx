#include <iostream>
#include <vector>
#include <stack>

long largestRectangle(std::vector<int> h) {
    std::stack<int> st;
    long max_area = 0;
    int tp, area_with_top, i = 0;
    while (i < h.size()) {
        if (st.empty() || h[st.top()] <= h[i]) {
            st.push(i);
            i++;
        } else {
            tp = st.top();
            st.pop();
            area_with_top = h[tp] * (st.empty() ? i : i - st.top() - 1);
            if (max_area < area_with_top) {
                max_area = area_with_top;
            }
        }
    }
    while (!st.empty()) {
        tp = st.top();
        st.pop();
        area_with_top = h[tp] * (st.empty() ? i : i - st.top() - 1);
        if (max_area < area_with_top) {
            max_area = area_with_top;
        }
    }
    return max_area;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> buildings(n);
    for (int i = 0; i < n; i++) {
        std::cin >> buildings[i];
    }
    long result = largestRectangle(buildings);
    std::cout << result << std::endl;
    return 0;
}