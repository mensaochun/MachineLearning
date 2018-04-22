# Regularization in machine learning

参考medium文章：[L1 Norm Regularization and Sparsity Explained for Dummies](https://medium.com/mlreview/l1-norm-regularization-and-sparsity-explained-for-dummies-5b0e4be3938a)

很多问题都没有理解。

目前有一个问题，L1 norm一般都设置为目标函数的限制条件，比如：L1 norm<c。然后将这个限制条件加入到目标函数当中。但是，神经网络中并没有这个限制条件，这个时候怎么理解？

objective function=loss+λ(L1_norm-c)

如果c为常数，这种情况实际上λ实际上就是一个解，不是一个惩罚稀疏。因为这个时候解释唯一的。

objective function=loss+λL1_norm

如果c不是常数，这个时候λ可以看作是一个惩罚系数。