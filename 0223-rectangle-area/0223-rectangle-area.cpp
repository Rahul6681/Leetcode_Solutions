class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        long long area1 = (long long)(ax2 - ax1) * (ay2 - ay1);
        long long area2 = (long long)(bx2 - bx1) * (by2 - by1);

        long long overlapWidth = max(0LL, (long long)(min(ax2, bx2) - max(ax1, bx1)));
        long long overlapHeight = max(0LL, (long long)(min(ay2, by2) - max(ay1, by1)));
        long long overlapArea = overlapWidth * overlapHeight;

        return area1 + area2 - overlapArea;
    }
};