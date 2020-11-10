from sklearn.utils import all_estimators
import warnings

# classifier 알고리즘 모두 추출
warnings.filterwarnings('ignore')
allAlgorithms = all_estimators(type_filter="classifier")
print("\n====== classifier ======")
for(name, algorithm) in allAlgorithms:
    print(name)

allAlgorithms = all_estimators(type_filter="regressor")
print("\n====== regressor ======")
for(name, algorithm) in allAlgorithms:
    print(name)

allAlgorithms = all_estimators(type_filter="cluster")
print("\n====== cluster ======")
for(name, algorithm) in allAlgorithms:
    print(name)

allAlgorithms = all_estimators(type_filter="transformer")
print("\n====== transformer ======")
for(name, algorithm) in allAlgorithms:
    print(name)