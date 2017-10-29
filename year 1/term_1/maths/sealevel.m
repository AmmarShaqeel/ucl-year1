function sealevel()
    global dataDate;
    global dataHeight;
    dataDate = [1915.375,1915.458,1915.542,1915.625,1915.708,1915.792,1915.875,1915.958,1916.042,1916.125,1916.208,1916.292,1916.375,1916.458,1916.542,1916.625,1916.708,1916.792,1916.875,1916.958,1917.042,1917.125,1917.208,1917.292];
    dataHeight = [6952,6962,6937,6944,6986,6985,7041,7164,6931,6943,7081,6865,6973,6922,6853,6988,6925,7041,7095,7069,6960,6902,6950,6841];
    plot(dataDate,dataHeight)
    intercept()
    gradient()
    sigmaval = sigma(intercept,gradient)
    sigmaA(sigmaval)
    sigmaB(sigmaval)
end

function intercept = intercept()
    global dataDate;
    global dataHeight;
    intercept = ((sum((dataDate.*dataDate))*sum(dataHeight)) - (sum(dataDate)*sum(dataDate.*dataHeight)))...
        /(24*sum(dataDate.*dataDate) - (sum(dataDate))^2);
end

function gradient = gradient()
    global dataDate;
    global dataHeight;
    gradient =  (24*sum(dataDate.*dataHeight) - sum(dataDate)*sum(dataHeight))...
        /(24*sum((dataDate.*dataDate)) - sum(dataDate)^2);
end

function sigma = sigma(c, m)
    global dataDate;
    global dataHeight;
    sigma = ((1/(24-2)) * sum(dataHeight - (m*dataDate + c))^2)^0.5;
end

function sigmaA = sigmaA(sigma)
    global dataDate;
    global dataHeight;
    sigmaA = (sigma*(sum(dataDate.*dataDate))^0.5)...
        /(24*sum(dataDate.*dataDate) - (sum(dataDate)^2)^0.5);
end

function sigmaB = sigmaB(sigma)
    global dataDate;
    global dataHeight;
    sigmaB = (sigma*24^0.5)/(24*sum(dataDate.*dataDate) - (sum(dataDate)^2)^0.5);
end