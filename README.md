# 基因演算法與 NEAT 結合的神經網路進化架構

這個專案實現了一種新型演算法架構，結合基因演算法 (GA) 與 NEAT (NeuroEvolution of Augmenting Topologies) 演算法。其核心概念是利用基因演算法作為最佳化工具，來演化和優化各種不同的 NEAT 網路拓撲，從而實現更有效的神經網路結構搜索和優化。

## 專案概述

本專案使用 C++ 實現這種結合式演算法，提供了一個完整的框架用於神經網路的訓練、進化和評估。專案具有高度模組化的結構，支援多種資料集的測試和應用。

### 創新點

- **雙層進化策略**：使用基因演算法優化 NEAT 網路的演化路徑
- **自適應網路拓撲**：透過 NEAT 演算法自動調整網路結構，而基因演算法則優化這個過程
- **高效參數搜索**：結合兩種演化策略實現更快速的參數空間搜索
- **適用於複雜任務**：提高了處理複雜分類和迴歸任務的能力

### 主要功能

- 基因組 (Genome) 結構設計，包含節點 (Node) 和連結 (Link) 的管理
- 神經網路建構與前向傳播
- 種群 (Population) 進化與基因突變
- 適應性物種分類
- 支援多種誤差衡量方法
- 支援多種資料集的訓練和測試
- 高階基因演算法控制 NEAT 網路的演化過程

## 依賴項目

- C++14 相容的編譯器
- OpenMP (用於平行處理)

## 安裝與編譯

1. 克隆此專案到本機：
```bash
git clone [repository_url]
cd [repository_name]
```

2. 編譯專案：
```bash
make all
```

3. 編譯特定資料集測試：
```bash
make test_iris        # 編譯 iris 資料集測試
make test_mnist       # 編譯 mnist 資料集測試
make test_Arrhythmiat # 編譯 Arrhythmia 資料集測試
```

## 資料集支援

專案當前支援以下資料集：

- Iris: 鳶尾花分類
- MNIST: 手寫數字識別
- Arrhythmia: 心律不整診斷
- EpilepticSeizure: 癲癇發作檢測
- abalone: 鮑魚年齡預測
- SportsArticles: 體育文章分類
- XOR: 邏輯運算測試

## 使用方法

1. 訓練模型：
```bash
./test_iris.out       # 使用 iris 資料集訓練
./test_mnist.out      # 使用 mnist 資料集訓練
```

2. 測試神經網路功能：
```bash
./testNerveNetwork.out
```

3. 測試基因組功能：
```bash
./testGenome.out
```

## 專案架構

- `include/`: 包含所有頭文件
  - `NEAT.hpp`: 演算法基本參數與工具函數
  - `Genome.hpp`: 基因組結構定義
  - `NerveNetwork.hpp`: 神經網路結構定義
  - `GeneLink.hpp` & `GeneNode.hpp`: 基因連結和節點定義
  - `Organism.hpp` & `Population.hpp`: 有機體和種群管理

- `src/`: 包含所有源代碼實現
  - NEAT 核心算法實現
  - 各種資料集的處理器實現

- `test/`: 包含測試代碼
  - `test_genome.cpp`: 基因組功能測試
  - `test_nerve_network.cpp`: 神經網路功能測試
  - `test_pop.cpp`: 种群進化功能測試

- `data_source/`: 包含各種數據集
  - `iris.txt`, `mnist.txt` 等資料檔案

## NEAT 參數設置

在 `NEAT.hpp` 和 `NEAT.cpp` 中定義了算法的關鍵參數：

- `disjoint_coeff`: 基因組不相交係數
- `excess_coeff`: 基因組超額係數
- `mutdiff_coeff`: 基因組突變差異係數
- `compat_threshold`: 物種相容性閾值
- `mutation_link`: 連結突變率
- `mutation_node`: 節點突變率
- `survival_rate`: 基因組存活率
- `reproduce_rate`: 基因組繁殖率
- `growth_time`: 成長時間
- `learning_rate`: 學習率

## 演算法工作原理

本專案的核心創新在於將基因演算法作為上層最佳化工具，用於指導 NEAT 網路的演化過程：

1. **基因編碼**：
   - 使用特殊的編碼方式表示 NEAT 網路的演化策略
   - 每個「個體」代表一種可能的 NEAT 網路演化路徑

2. **雙層選擇機制**：
   - 內層：NEAT 網路內部進行連結和節點的增刪和參數調整
   - 外層：基因演算法對不同 NEAT 網路結構的演化策略進行篩選

3. **適應度評估**：
   - 根據網路的表現評估基因適應度
   - 透過動態調整的適應度函數改進演化效率

4. **自適應突變**：
   - 根據學習進度動態調整突變率
   - 實現從粗糙搜索到精細優化的平滑過渡

## 與傳統 NEAT 的區別

相較於傳統的 NEAT 演算法，本專案的方法有以下優勢：

- **更高效的參數搜索**：基因演算法能夠更有效地探索大型參數空間
- **避免局部最優**：雙層演化策略增加了擺脫局部最優解的能力
- **更好的泛化能力**：產生的網路拓撲通常具有較佳的泛化性能
- **適用於更複雜的問題**：能夠處理更高維度、更複雜的資料集

## 貢獻與開發

歡迎提交 Pull Requests 和 Issues。在開發新功能或修復 bug 時，請確保遵循現有的代碼風格和架構。

## 參考文獻

- Stanley, K. O., & Miikkulainen, R. (2002). Evolving neural networks through augmenting topologies. Evolutionary computation, 10(2), 99-127.
- Holland, J. H. (1992). Genetic algorithms. Scientific American, 267(1), 66-73.
- Floreano, D., Dürr, P., & Mattiussi, C. (2008). Neuroevolution: from architectures to learning. Evolutionary Intelligence, 1(1), 47-62.