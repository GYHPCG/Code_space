# 卷积神经网络(Datawhale X 李宏毅苹果书AI夏令营)

卷积神经网络是一种非常典型的网络 架构，常用于图像分类等任务。

一张图像是一个三维的张量，其中一维代表图像的 宽，另外一维代表图像的高，还有一维代表图像的通道（channel）的数目

**通道**：彩色图像的每个像素都可以描述为红色（red）、绿色（green）、蓝色（blue）的组 合，这 3 种颜色就称为图像的 3 个色彩通道。这种颜色描述方式称为 RGB 色彩模型， 常用于在屏幕上显示颜色。

网络输入通常是向量，因此在将图片输入网络前，需要对网络进行“拉伸”。

![image-20240903162507328](https://cdn.jsdelivr.net/gh/GYHPCG/my_picgo/picture/image-20240903162507328.png)

## 感受野

对于图像识别，很多时候我们并不需要检测整张图像才能进行识别。如对于鸟、猫、狗三张照片，我们只需要看如头就能确定照片的类别。

![image-20240903194553754](https://cdn.jsdelivr.net/gh/GYHPCG/my_picgo/picture/image-20240903194553754.png)

为了将图片中的某个区域如头给检测出来，我们就用到了 **感受野**。神经网络会设定一个区域，即感受野（receptive field），每个神经元都只关心自己的感受野里面发生的事情，感受野是由我们自己决定的。

![image-20240903194739469](https://cdn.jsdelivr.net/gh/GYHPCG/my_picgo/picture/image-20240903194739469.png)

![image-20240903194804376](https://cdn.jsdelivr.net/gh/GYHPCG/my_picgo/picture/image-20240903194804376.png)

### 感受野设计

图像识别中高跟宽大小叫做核大小，之所以不说深度，因为深度等于通道数。经典感受野核大小为**3x3**。

一般同一个感受野会有一组神经元去守备这个范围，比如 64 个或者是 128 个神经元去守 备一个感受野的范围。

**步幅**(stride): 旧感受野移动到一个新的感受野所移动的量。一般设为1和2.

![image-20240903195604270](https://cdn.jsdelivr.net/gh/GYHPCG/my_picgo/picture/image-20240903195604270.png)

![image-20240903195633091](https://cdn.jsdelivr.net/gh/GYHPCG/my_picgo/picture/image-20240903195633091.png)

当感受野超出了图像的范围，为了让剩余的边界视野不会丢失，我们会进行**填充(padding)**，填充就是补值，一般使用零填充（zero padding），超出范围就补 0，如果感受野有一部分超出图像的范围 之外，就当做那个里面的值都是 0。其实也有别的补值的方法，比如补整张图像里面所有值的 平均值或者把边界的这些数字拿出来补没有值的地方。

![image-20240903200044318](https://cdn.jsdelivr.net/gh/GYHPCG/my_picgo/picture/image-20240903200044318.png)

,

## 共享参数(不变性)

对于某一个模式，如鸟嘴，可能出现在图片左上角、中间等。那么对于这些检测鸟嘴的神经元做的事情是一样的，只是它们守备的范围不一样。既然如 此，其实没必要每个守备范围都去放一个检测鸟嘴的神经元。如果不同的守备范围都要有一 个检测鸟嘴的神经元，参数量会太多了，因此需要做出相应的简化。

**共享参数**：两个神经元的权重完全是一样的

![image-20240903200452972](https://cdn.jsdelivr.net/gh/GYHPCG/my_picgo/picture/image-20240903200452972.png)

## 1和2总结

全连接网络是弹性最 大的。全连接网络可以决定它看整张图像还是只看一个范围，如果它只想看一个范围，可以 把很多权重设成 0。但加上感受野的概念以后，只能看一个小范围，网络的弹性是变小的。参数共享 又进一步限制了网络的弹性。本来在学习的时候，每个神经元可以各自有不同的参数，它们 可以学出相同的参数，也可以有不一样的参数。但是加入参数共享以后，某一些神经元无论 如何参数都要一模一样的，这又增加了对神经元的限制。**而感受野加上参数共享就是卷积层 （convolutional layer）**，用到卷积层的网络就叫卷积神经网络。

![image-20240903201042600](https://cdn.jsdelivr.net/gh/GYHPCG/my_picgo/picture/image-20240903201042600.png)

==卷积层是专门为图像设计的，感受野、参数共享都是为图像设计==

如果把它用在图像之外的任务，就要仔细 想想这些任务有没有图像用的特性。

![image-20240903211718134](https://cdn.jsdelivr.net/gh/GYHPCG/my_picgo/picture/image-20240903211718134.png)

![image-20240903211752486](https://cdn.jsdelivr.net/gh/GYHPCG/my_picgo/picture/image-20240903211752486.png)

## 池化(汇聚)

把一张比较大的图像做**下采样（downsampling**）， 把图像偶数的列都拿掉，奇数的行都拿掉，图像变成为原来的 1/4，但是不会影响里面是什么 东西。如图 4.26 所示，把一张大的鸟的图像缩小，这张小的图像还是一只鸟。

![image-20240903211938942](https://cdn.jsdelivr.net/gh/GYHPCG/my_picgo/picture/image-20240903211938942.png)

对于上面的现象，我们可以使用**池化** 来处理图像，汇聚没有参数，所以它不是一个层，它里面 没有权重，它没有要学习的东西，它只是一个操作运算。

如 **Max pooling 最大池化**:

![image-20240903212645395](https://cdn.jsdelivr.net/gh/GYHPCG/my_picgo/picture/image-20240903212645395.png)

![image-20240903212802317](https://cdn.jsdelivr.net/gh/GYHPCG/my_picgo/picture/image-20240903212802317.png)

每个滤波器都产生一组数字，要做汇聚的时候，把这些数字分组，可以 2 × 2 个 一组，3 × 3、4 × 4 也可以，这个是我们自己决定的，图 4.27 中的例子是 2 × 2 个一组。汇聚 有很多不同的版本，以最大汇聚（max pooling）为例。最大汇聚在每一组里面选一个代表， 选的代表就是最大的一个，如图 4.28 所示。除了**最大汇聚**，还有平均**汇聚（mean pooling**）， 平均汇聚是取每一组的平均值。

一般在实践上，往往就是卷积跟汇聚交替 使用，可能做几次卷积，做一次汇聚。比如两次卷积，一次汇聚。不过汇聚对于模型的性能 （performance）可能会带来一点伤害。

汇聚最主要的作用是减少运算量， 通过下采样把图像变小，从而减少运算量。

![image-20240903213128531](https://cdn.jsdelivr.net/gh/GYHPCG/my_picgo/picture/image-20240903213128531.png)



## 卷积神经网络的应用：下围棋

下围棋、语音上和文字处理上

![image-20240903213257164](https://cdn.jsdelivr.net/gh/GYHPCG/my_picgo/picture/image-20240903213257164.png)

==**CNN不能处理图像放大缩小或者是旋转的问题**==

卷积神经网络并没有想像的那么强。因此在做图像识别的时候往往都要做数据增强。

**数据增强**就是把训练数据每张图像里面截一小块出来放大，让卷积神经网络看过不 同大小的模式；把图像旋转，让它看过某一个物体旋转以后长什么样子，卷积神经网络才会做 到好的结果。卷积神经网络不能够处理缩放（scaling）跟旋转（rotation）的问题，但 Special Transformer Layer 网络架构可以处理这个问题。