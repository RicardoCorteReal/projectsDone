%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TItle: Insertion Sort Algorithm Visualisation for Reversed Arrays
% Author: 
% Rev Date: 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all;
close all;
clc;
N = 16; % Length of array to be sorted
V = N:-1:1; % Generate an array containing integers from N down to 1
changeNumber = 1;
arrayState(1:N,changeNumber) = V;
changeNumber = changeNumber + 1;

for currentPivot = 2:N
    pivot = V(currentPivot);
    currentPos = currentPivot;
    while ((currentPos > 1) && ( V(currentPos - 1) > pivot))
        V(currentPos) =  V(currentPos - 1);
        arrayState(1:N,changeNumber) = V;
        currentPos = currentPos - 1;
        changeNumber = changeNumber + 1;
    end
    V(currentPos) = pivot;
    arrayState(1:N,changeNumber) = V;
    changeNumber = changeNumber + 1;
end

figure;
imagesc(arrayState);
axis square;
colormap jet;
ylabel('Element Number','FontSize',14);
xlabel('Array State','FontSize',14);
% Store High-resolution Image Suitable for use in Reports
print -f1 -r300 -dbmp insertionSortVisualisation.bmp