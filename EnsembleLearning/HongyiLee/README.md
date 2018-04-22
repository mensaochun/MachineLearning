## Ensemble

![042215304686_0Ensemble(v6)_1](./pics/042215304686_0Ensemble(v6)_1.jpg)

![042215304686_0Ensemble(v6)_2](./pics/042215304686_0Ensemble(v6)_2.jpg)

![042215304686_0Ensemble(v6)_3](./pics/042215304686_0Ensemble(v6)_3.jpg)

## Bagging

![042215304686_0Ensemble(v6)_4](./pics/042215304686_0Ensemble(v6)_4.jpg)



先回顾一些之前的方差和偏差理论。误差来源于偏差和方差（此处不考虑噪声）。

![042215304686_0Ensemble(v6)_5](./pics/042215304686_0Ensemble(v6)_5.jpg)

如果对一个复杂度比较高，方差会相应比较高。对这样的多个模型进行平均，会使结果较准确。

![042215304686_0Ensemble(v6)_6](./pics/042215304686_0Ensemble(v6)_6.jpg)

进行有放回的采样，训练多个模型，进行平均或者投票。

![042215304686_0Ensemble(v6)_7](./pics/042215304686_0Ensemble(v6)_7.jpg)

对容易overfit的模型进行bagging是比较好的选择。决策树就是比较容易overfitting的分类器，因此选择决策树作为个体学习器是很好的选择。

![042215304686_0Ensemble(v6)_8](./pics/042215304686_0Ensemble(v6)_8.jpg)

![042215304686_0Ensemble(v6)_9](./pics/042215304686_0Ensemble(v6)_9.jpg)

![042215304686_0Ensemble(v6)_10](./pics/042215304686_0Ensemble(v6)_10.jpg)

![042215304686_0Ensemble(v6)_11](./pics/042215304686_0Ensemble(v6)_11.jpg)

![042215304686_0Ensemble(v6)_12](./pics/042215304686_0Ensemble(v6)_12.jpg)

随机森林的随机性来自于随机选择特征。疑问：每棵树的深度呢？

![042215304686_0Ensemble(v6)_13](./pics/042215304686_0Ensemble(v6)_13.jpg)

bagging是多个个体强学习器的组合，boosting相反，它是多个若学习器的组合。

![042215304686_0Ensemble(v6)_14](./pics/042215304686_0Ensemble(v6)_14.jpg)

![

]'[p;ol,ikjnhbgvfcdxz042215304686_0Ensemble(v6)_15](./pics/042215304686_0Ensemble(v6)_15.jpg)

![042215304686_0Ensemble(v6)_16](./pics/042215304686_0Ensemble(v6)_16.jpg)

![042215304686_0Ensemble(v6)_17](./pics/042215304686_0Ensemble(v6)_17.jpg)

![042215304686_0Ensemble(v6)_18](./pics/042215304686_0Ensemble(v6)_18.jpg)

![042215304686_0Ensemble(v6)_19](./pics/042215304686_0Ensemble(v6)_19.jpg)

![042215304686_0Ensemble(v6)_20](./pics/042215304686_0Ensemble(v6)_20.jpg)

![042215304686_0Ensemble(v6)_21](./pics/042215304686_0Ensemble(v6)_21.jpg)

![042215304686_0Ensemble(v6)_22](./pics/042215304686_0Ensemble(v6)_22.jpg)

![042215304686_0Ensemble(v6)_23](./pics/042215304686_0Ensemble(v6)_23.jpg)

![042215304686_0Ensemble(v6)_24](./pics/042215304686_0Ensemble(v6)_24.jpg)

![042215304686_0Ensemble(v6)_25](./pics/042215304686_0Ensemble(v6)_25.jpg)

![042215304686_0Ensemble(v6)_26](./pics/042215304686_0Ensemble(v6)_26.jpg)

![042215304686_0Ensemble(v6)_27](./pics/042215304686_0Ensemble(v6)_27.jpg)

![042215304686_0Ensemble(v6)_28](./pics/042215304686_0Ensemble(v6)_28.jpg)

![042215304686_0Ensemble(v6)_29](./pics/042215304686_0Ensemble(v6)_29.jpg)

![042215304686_0Ensemble(v6)_30](./pics/042215304686_0Ensemble(v6)_30.jpg)

![042215304686_0Ensemble(v6)_31](./pics/042215304686_0Ensemble(v6)_31.jpg)

![042215304686_0Ensemble(v6)_32](./pics/042215304686_0Ensemble(v6)_32.jpg)

![042215304686_0Ensemble(v6)_33](./pics/042215304686_0Ensemble(v6)_33.jpg)

![042215304686_0Ensemble(v6)_34](./pics/042215304686_0Ensemble(v6)_34.jpg)

![042215304686_0Ensemble(v6)_35](./pics/042215304686_0Ensemble(v6)_35.jpg)

![042215304686_0Ensemble(v6)_36](./pics/042215304686_0Ensemble(v6)_36.jpg)

实际上，Adaboosting只是一种特例，可以用Gradient boosting来。

![042215304686_0Ensemble(v6)_37](./pics/042215304686_0Ensemble(v6)_37.jpg)

不考虑学习率。

方向要一样。

![042215304686_0Ensemble(v6)_38](./pics/042215304686_0Ensemble(v6)_38.jpg)

注意，以下ppt有错，是$g_{t-1}$。由于不考虑参数，这里只要他们的方向一致，scale不用管。

Adaptive boosting实际上是Garadient boosting的特例。如果选用不同的loss function可以得到其他的情况。

![042215304686_0Ensemble(v6)_39](./pics/042215304686_0Ensemble(v6)_39.jpg)

![042215304686_0Ensemble(v6)_40](./pics/042215304686_0Ensemble(v6)_40.jpg)

![042215304686_0Ensemble(v6)_41](./pics/042215304686_0Ensemble(v6)_41.jpg)

![042215304686_0Ensemble(v6)_42](./pics/042215304686_0Ensemble(v6)_42.jpg)

![042215304686_0Ensemble(v6)_43](./pics/042215304686_0Ensemble(v6)_43.jpg)

注意要将training data分成两个部分。

![042215304686_0Ensemble(v6)_44](./pics/042215304686_0Ensemble(v6)_44.jpg)

![042215304686_0Ensemble(v6)_45](./pics/042215304686_0Ensemble(v6)_45.jpg)

