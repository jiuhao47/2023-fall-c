# Gobang GUI软件使用说明

### 一、如何启动

1. 将下载的文件`gobang_vs.exe`放在一个目录下

   ![Pic1](E:\VSCODE\Gobang\Doc\Pic\Pic1.png)

2. 右键点击目录（文件夹）空白处，点击在终端中打开。

   ![Pic2](E:\VSCODE\Gobang\Doc\Pic\Pic2.png)

3. 输入`cmd`，回车。

   ![Pic3](E:\VSCODE\Gobang\Doc\Pic\Pic3.png)

4. 键入`gobang_vs`，回车便可以进入程序界面（人人对战）。

   ![Pic4](E:\VSCODE\Gobang\Doc\Pic\Pic4.png)

5. 键入`gobang_vs -b "E:\VSCODE\Gobang\test_b.exe" -w "E:\VSCODE\Gobang\test_w.exe"`，其中`E:\VSCODE\Gobang\test_b.exe`和`E:\VSCODE\Gobang\test_w.exe`为测试用黑方和白方二进制程序的绝对路径。运行结果如下

   ![Pic5](E:\VSCODE\Gobang\Doc\Pic\Pic5.png)

### 二、参数详解
1. **指定黑方白方`-b` `-w`**

   ```shell
   gobang_vs -b [黑方二进制程序（编译生成）的绝对路径] -w [白方二进制程序（编译生成）的绝对路径]
   
   如果不输入-b或-w（或者都不输入），则不输入的部分默认为人类操作
   
   示例：
   
   gobang_vs 黑白双方均为人类；
   gobang_vs -b "E:\VSCODE\Gobang\test_b.exe"，黑方为机器，白方为人类；
   ```

2. **使用相对路径 `-cwd`**

   ```shell
   示例：
   gobang_vs -cwd "E:\VSCODE\Gobang" -b test_b -w test_w
   
   注：test_b.exe，test_w文件均在E:\VSCODE\Gobang目录下
   ```

3. **不使用相对路径**

   ```shell
   示例：
   gobang_vs -b "E:\VSCODE\Gobang\test_b.exe" -w "E:\VSCODE\Gobang\test_w.exe"
   
   E:\VSCODE\Gobang\test_b.exe，E:\VSCODE\Gobang\test_w.exe分别为test_b.exe和test_w.exe的绝对路径
   ```


### 三、输入输出规范

此程序对黑方白方的程序输入输出作了如下规范：

1. 启动检测：

   在输入黑方白方的函数（如用于输入黑方白方的`scanf`函数前)，前的两条语句应该为：

   ```C 
   printf("readytogetplayer"\n);
   fflush(stdout);
   ```

   程序片段示例

   ```C
   printf("readytogetplayer"\n);
   fflush(stdout);
   //必须紧跟着输入函数
   scanf("%s",player);
   ```

2. 输入及输出规范

   > 程序应当输出该步骤的落子，并接受对方的下一落子

   对于棋子坐标的传输，规范统一采用下列形式：

   ```
   "step(%d,%d)\n"
   ```

   对于一次交互过程：

   黑方机器先手，其先输出字符串

   ```
   step(1,3)//表明黑方机器在坐标(1,3)处落子
   ```

   通过`gobang_vs`程序，白方机器获取到黑方机器的输出，然后给出白方机器的落子，输出字符串

   ```
   step(2,3)//表明白方机器在(2,3)处落子
   ```

   且对于输出同学们编写的C语言程序中的用于输出落子信息用的函数：

   ```C
   printf,puts等 
   ```

   其输出格式规定为

   ```C
printf("step(%d,%d)\n",x,y);
   ```
   
   且其下一条语句必须为
   
   ```c
   fflush(stdout);
   ```
   
   
   > 原理部分（省流可跳过）：`fflush(stdout)`的作用本质为清空标准输出`stdout`的缓冲区，本程序采用标准输入输出实现白方与黑方的交互，需保证每次传入的格式为`"step(%d,%d)\n"`