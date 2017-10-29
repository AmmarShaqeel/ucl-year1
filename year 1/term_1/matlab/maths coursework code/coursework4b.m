clear
clc

data = [1460 1240 1230 1270 861 1355 612 822 1370 1380]

dataM = mean(data)

sd = sqrt((sum((data-mean(data)).^2)/(numel(data)-1)))

