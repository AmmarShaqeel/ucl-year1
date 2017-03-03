%clearing variables, etc
clc
clear all

%displays message asking for user input
prompt = 'input file name'; 
disp(prompt); 

fileName = input('','s'); %assigns user input to variable

dataSingle = fread(fopen(fileName), 'single'); %opens file as single
dataDouble = fread(fopen(fileName), 'double'); %opens file as a double
dataInt32 =  fread(fopen(fileName), 'int32');  %opens file as in32

fid = fopen(strcat(string(fileName),'.txt'),'wt'); %creates text file, overwriting one if it exists


%if statement below check datatypes to find the correct value - has two checks: range (13-383) 
% and if array contains any decmials
if min(dataSingle) >= 13 & max(dataSingle) <= 383 & max(rem(dataSingle,1)) == 0
    offsetData = dataSingle;
elseif min(dataDouble) >= 13 & max(dataDouble) <= 383 & max(rem(dataDouble,1)) == 0
    offsetData = dataDouble;
elseif min(dataInt32) >= 13 & max(dataInt32) <= 383 & max(rem(dataInt32,1)) == 0
    offsetData = dataInt32;
end

%finding offset - as space (ascii character 32) is the most common character
offset = mode(offsetData) - 32;

%displaying message
realData = offsetData - offset;
message = char(realData);
transpose(message)

%writing message to text file
fprintf(fid, transpose(message));

%closing all open files
fclose('all');