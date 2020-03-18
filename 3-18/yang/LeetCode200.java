package com.ibuyi.interview.leetcode;

public class LeetCode200 {
    //网格四周可以看做全是水，所以我们只需要遍历网格，找到不是互相连接的的陆地的个数就可以。
    public int numIslands(char[][] grid) {
        if(grid==null){
            return 0;
        }

        int count=0;//岛屿数量
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                if(grid[i][j]=="1".charAt(0)){
                    count++;
                    judge(grid,i,j);
                }
            }
        }
        return count;
    }
    public static void judge(char[][] grid,int x,int y) {
        //只要水平或者垂直是水 就是岛屿
        grid[x][y] = '2';
        if (x > grid.length - 1 && y > grid[0].length - 1) {
            return;
        }
        if (x < grid.length - 1 && grid[x + 1][y] == '1') {//向下
            judge(grid, x + 1, y);
        }
        if (y < grid[0].length - 1 && grid[x][y + 1] == '1') {//向右
            judge(grid, x, y + 1);
        }
        if (x > 0 && grid[x - 1][y] == '1') {//向上
            judge(grid, x - 1, y);
        }
        if (y > 0 && grid[x][y - 1] == '1') {//向左
            judge(grid, x, y - 1);
        }

    }
}
