import random

filename = "./data_source/EpilepticSeizure"
train_rate = 0.3
valid_rate = 0.1

src = open(filename+".txt","r")
src_ls = src.readlines()

random.shuffle(src_ls)

out_filename = filename.replace('data_source','dataset')
f_train = open(out_filename+"_train.txt","w")
f_valid = open(out_filename+"_valid.txt","w")
f_test = open(out_filename+"_test.txt","w")

size = len(src_ls)
for i in range(size):
    data = src_ls[i]
    if i < size * train_rate :
        f_train.write(data)
    elif i < size * (train_rate + valid_rate):
        f_valid.write(data)
    else:
        f_test.write(data)