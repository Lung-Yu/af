#ifndef TYGR_NERVE_NETWORK_HPP
#define TYGR_NERVE_NETWORK_HPP

#include <iostream>
#include <memory>
#include <vector>
#include <cmath>

#include "Genome.hpp"
#include "NerveNeuron.hpp"
#include "NerveSynapse.hpp"
#include "DataHelper.hpp"
#include "MeanSquaredError.hpp"

class Genome;
class NerveNeuron;
class NerveSynapse;

class NerveNetwork
{
  protected:
    double fitness;
    std::vector<double> accumulate_error;

    std::shared_ptr<Genome> genome;

    std::vector<std::shared_ptr<NerveNeuron>> in_nodes;
    std::vector<std::shared_ptr<NerveNeuron>> out_nodes;
    std::vector<std::shared_ptr<NerveNeuron>> hidden_nodes;

    std::vector<std::shared_ptr<NerveSynapse>> links;

    void establishedComponent();
    void establishedNodes();
    void establishedLinks();
    void nodes_recover();
    double get_accuracy(int mod);
    
    std::shared_ptr<NerveNeuron> find_neuron(int id);
  public:
    NerveNetwork(std::shared_ptr<Genome> g);
    ~NerveNetwork();
    
    double get_inference_accuracy();
    double get_train_accuracy();
    double get_valid_accuracy();
    void train(int times);
    void train_SGD(int times);
    double inference(std::shared_ptr<DataHelper> data_helper);
    double inference(int type);
    std::shared_ptr<Genome> toGenome();
    void show_info();
};

#endif