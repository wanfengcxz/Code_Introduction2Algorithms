//
// Created by 晚风吹行舟 on 2022/6/20.
//

// 自顶向下 递归 超出时间限制
int climb_stairs_top_down(int n) {
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return climb_stairs_top_down(n - 1) + climb_stairs_top_down(n - 2);
}

// 自底向上法 动态规划
int climb_stairs_bottom_up(int n){
    if (n==1||n==2)
        return n;
    int *arr = new int[n+1];
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3;i<=n;i++)
        arr[i] = arr[i-1]+arr[i-2];
    return arr[n];
}