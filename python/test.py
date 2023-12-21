'''
Descripttion: my code for learning
Author: chenggong Pan
Date: 2023-11-09 21:15:26
LastEditors: chenggong Pan
LastEditTime: 2023-12-03 12:44:53
'''
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_squared_error
from math import sqrt

# 加载数据
data = pd.read_csv('your_data.csv')


# 选择特征和目标变量
X = data[['feature1', 'feature2', 'feature3']]  # 选择作为特征的列
y = data['target']  # 目标变量

# 划分数据集
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 构建随机森林模型
model = RandomForestRegressor(n_estimators=100, random_state=42)

# 训练模型
model.fit(X_train, y_train)


# 预测测试集
predictions = model.predict(X_test)

# 计算均方根误差（RMSE）
rmse = sqrt(mean_squared_error(y_test, predictions))
print(f"模型的均方根误差（RMSE）: {rmse}")

# 分析并可视化各特征对模型的贡献度。
import matplotlib.pyplot as plt

# 获取特征重要性
importances = model.feature_importances_

# 将特征重要性以条形图展示
indices = range(len(importances))
plt.title('特征重要性')
plt.bar(indices, importances, color='b', align='center')
plt.xticks(indices, X.columns)
plt.ylabel('重要性')
plt.show()

# 为了进一步提高模型的性能，你可以使用网格搜索进行参数调优
from sklearn.model_selection import GridSearchCV

# 定义参数网格
param_grid = {
    'n_estimators': [100, 200, 300],
    'max_features': ['auto', 'sqrt'],
    'max_depth': [10, 20, 30]
}


# 网格搜索
grid_search = GridSearchCV(estimator=model, param_grid=param_grid, cv=3, n_jobs=-1, verbose=2)
grid_search.fit(X_train, y_train)

# 打印最佳参数
print(f"最佳参数: {grid_search.best_params_}")
