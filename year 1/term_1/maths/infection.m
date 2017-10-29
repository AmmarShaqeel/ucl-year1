function infection()
    plot(iterate(12));
end

function data = dS(S)
    data = 0.001*(1000-S)*S;
end
function  data = Splus1(S)
    data = S+dS(S);
end
function data = iterate(i)
    data = [2 0];
    ii = 1;
    Si = 2;
    while ii<=(i-1)
        Sii = Splus1(Si)
        Si = Sii
        data = [data;[Sii ii]]
        ii = ii+1
    end
end