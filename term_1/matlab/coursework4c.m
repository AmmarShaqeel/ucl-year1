clear
clc

data = [810 735 259 1290 1125 528 622 468 664 717]

dataM = mean(data)

sd = sqrt((sum((data-mean(data)).^2)/(numel(data)-1)))

