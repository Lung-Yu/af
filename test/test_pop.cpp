#include "Population.hpp"

#include <memory>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Innovation.hpp"
#include "GeneInfoController.hpp"
#include "GeneModelSaver.hpp"

using namespace std;

void test_innovation();
void save_model_sample();

void run(const int population_size,const int evolution_time,int inputSize,int outputSize,char* model_name,char* model_finish);

int main()
{
    unsigned seed = (unsigned)time(NULL); // 取得時間序列
    srand(seed);
    run(50,250,784,10,"model-mnist2","model-mnist2");
    // run(50,250,178,2,"model-Arrhythmiat","model-Arrhythmiat");
    // run(50,250,276,2,"model-EpilepticSeizure2","model-finsh-EpilepticSeizure2");
    // run(50,250,8,3,"model-abalone","model-finsh-abalone");
    // run(50,250,59,2,"model-sportsArticles2","model-finsh-sportsArticles2");

    return 0;
}

void run(const int population_size,const int evolution_time,int inputSize,int outputSize,char* model_name,char* model_finish){
    auto pop = make_unique<Population>(inputSize, outputSize, population_size);
    // pop->enableGrowthState();
    pop->disableGrothState();
    pop->showInfo();
    cout << "***************************start***************************" << endl;
    for (int i = 0; i < evolution_time; i++)
    {
        cout << "evolution [" << i << "/" << evolution_time << "]";
        pop->evolution();
        pop->report_out();
        pop->save_best_organism(model_name);


        if(pop->getBest()->getTrainAccuracy() >= 0.95)
            break;
    }
    pop->save_best_organism(model_finish);
    auto info_control = GeneInfoController::getInstance();
    info_control->showInfo();
    auto innovation = Innovation::getInstance();
    innovation->showInfo();
}

void test_innovation()
{
    cout << Innovation::getInstance()->applyLinkInnovation() << endl;
    cout << Innovation::getInstance() << endl;
    cout << Innovation::getInstance()->applyNodeInnovation() << endl;
    cout << Innovation::getInstance()->applyNodeInnovation() << endl;
    Innovation::getInstance()->showInfo();
}
