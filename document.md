CSAPP DataLab 实验报告
1. 规则检查截图：终端执行 ./check_ops.py bits.c 的完整输出截图
![alt text](规则检查.PNG)
2. 功能测试截图：终端执行 ./btest的完整输出截图（显示 110/110 满分）
![alt text](正确性检查.PNG)
3. 各函数实现思路（按题目顺序，每道题一两句话说明核心方法即可）
   signMask：通过 1 左移 31 位得到符号位掩码
   bitXor：利用德摩根律，仅用～和 & 实现异或
   negativePart：用符号位扩展做掩码，负数时返回绝对值
   copyByteWithin：移位提取指定字节，掩码清除目标位置后合并
   logicalShift：构造掩码清除算术右移的符号扩展位
   swapNibblePairs：构造半字节掩码，高低四位交换
   secondLowestZeroBit：先找最低位 0，填充后再找第二位 0
   oddParity：折叠异或法计算奇偶校验位
   rotateRightBits：拆分左右两部分移位后合并，实现循环右移
   roundEvenPow2：构造偏移量，银行家舍入到 2 的幂倍数
   midpointTowardFirst：用无溢出中点公式，符号判断向 x 方向取整
   isBetweenEitherOrder：两次做差判断符号，异号说明 x 在区间内
   mul5Sat：拆分为 x*4+x，逐次判断溢出，饱和到极值
   classifyAdd3：分步相加，两次判断正溢出和负溢出
   floatScaleThreeHalves：统一有效数字 + 阶码模型，乘 3 阶码减 1，银行家舍入
   floatRoundEven：按阶码拆分整数小数部分，银行家舍入到整数
   float_i2f：定位最高有效位，计算阶码，移位截取尾数并舍入
   bitCount：分治并行计数法，逐层合并 1 的个数
   bitReverse：分治交换法，从 1 位到 16 位逐层交换