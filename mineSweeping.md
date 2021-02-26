# 扫雷

## 设计

> 1. 将game页面程序与game方法实现分离(创建game.h,game.c实现类)
> 2. 方法说明
>    1. test() 程序入口
>    2. InitBoard() 初始化数组，
>    3. DisplayBoard() 打印数组,
>    4.  SetMine() 布置地雷,
>    5. FindMine() 排雷 
>    6. win() 判断排雷是否成功
>    7. menu() 用户页面
> 3. 特殊参数 
>    1. EASY_COUNT 地雷数量 
>    2. ROW X坐标 
>    3. COL Y坐标 
>    4. ROWS 整个数组X坐标
>    5. COLS  整个数组Y坐标
> 4. 总体思路
>    1. 数组设置的X，Y轴要大于游戏本身一圈即(X+2，Y+2)，为便于FindMine方法中的坐标周遭地雷检测
>    2. 在关于SetMine，FindMine，win方法调用时X，Y坐标应+1，而玩家传来的坐标则无需修改
>    3. FindMine中需完成踩雷检测，坐标重复检测，地雷检测，排雷成功与否的检测，在坐标周遭地雷检测中还未完成连续检测

