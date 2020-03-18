package com.ibuyi.interview.leetcode;

public class LeetCode836 {
    /*
    矩形以列表 [x1, y1, x2, y2] 的形式表示，其中 (x1, y1) 为左下角的坐标，(x2, y2) 是右上角的坐标。
    如果相交的面积为正，则称两矩形重叠。需要明确的是，只在角或边接触的两个矩形不构成重叠。
    给出两个矩形，判断它们是否重叠并返回结果。
     */
    public static boolean isRectangleOverlap(int[] rec1, int[] rec2) {
           //x2<x3 ||x4<x1 || y4<y1 || y3>y2 这几种情况不相交
           return !(rec1[2]<=rec2[0]||rec2[2]<=rec1[0]||rec2[3]<=rec1[1]||rec2[1]>=rec1[3]);
    }

}
