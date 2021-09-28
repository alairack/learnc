# txt_photo  (txt文本文档转换为“图片”)
## 1.如何运行
从main分支中下载.c后缀的文件，使用gcc,tcc,visual C 等编译器编译后运行即可。如果报错，请尝试使用c99标准。如为".py"后缀的python文件则不需要编译。
## 2.程序清单
- txt_photo: 把一个内含一些0~9数字，数字间用空格隔开的文本文件（如下图所示），按数字大小转换成相应大小的字符，再输出至标准输出和当前目录下"output.txt"文件中。以此来制作一张"图片"。运行时，需要把要转换的文本文件放在与exe同级的目录下，第一个参数输入完整文件名
 
 ![文本文件样本](https://i.loli.net/2021/09/23/rMHVqSp83IOL5lb.png)                  ![运行截图](https://i.loli.net/2021/09/23/7Tk9oJabQmtRhDf.png)
  ![python运行截图](https://i.loli.net/2021/09/28/612PxVWsYwO84dF.png)
  
