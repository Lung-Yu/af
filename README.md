# NEAT 神經網路進化演算法實現

這個專案實現了 NEAT (NeuroEvolution of Augmenting Topologies) 演算法，這是一種用於優化人工神經網路結構和權重的進化算法。NEAT 透過逐漸增加結構複雜度來尋找最適合解決問題的神經網路拓撲。

## 專案概述

本專案使用 C++ 實現 NEAT 演算法，提供了一個完整的框架用於神經網路的訓練、進化和評估。專案具有高度模組化的結構，支援多種資料集的測試和應用。

### 主要功能

- 基因組 (Genome) 結構設計，包含節點 (Node) 和連結 (Link) 的管理
- 神經網路建構與前向傳播
- 種群 (Population) 進化與基因突變
- 適應性物種分類
- 支援多種誤差衡量方法
- 支援多種資料集的訓練和測試

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

## 貢獻與開發

歡迎提交 Pull Requests 和 Issues。在開發新功能或修復 bug 時，請確保遵循現有的代碼風格和架構。

## 參考文獻

- Stanley, K. O., & Miikkulainen, R. (2002). Evolving neural networks through augmenting topologies. Evolutionary computation, 10(2), 99-127.