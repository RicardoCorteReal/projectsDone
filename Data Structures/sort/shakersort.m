%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Title: Shaker Sort Algorithm Visualisation for Reversed Arrays
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
isSorted = false;
secondlastUnknownPos = numel(V)-1;
currentPos = 0;
while(~isSorted)
    % Forward bubble sort 
    isSorted = true;
    currentPos = currentPos + 1;    
    for i = currentPos:secondlastUnknownPos
        if(V(i)>V(i+1))
            temp = V(i);
            V(i) = V(i+1);
            V(i+1) = temp;
            isSorted = false;
            arrayState(1:N,changeNumber) = V;
            changeNumber = changeNumber + 1;
        end % if
    end % for
    if isSorted == false
        % Backwards bubble sort 
        isSorted = true;
        secondlastUnknownPos = secondlastUnknownPos - 1;
        for i = secondlastUnknownPos:-1:currentPos
            if(V(i)>V(i+1))
                temp = V(i);
                V(i) = V(i+1);
                V(i+1) = temp;
                isSorted = false;
                arrayState(1:N,changeNumber) = V;
                changeNumber = changeNumber + 1;
            end % if
        end
    end
end % while

figure;
imagesc(arrayState);
axis square;
colormap jet;
ylabel('Element Number','FontSize',14);
xlabel('Array State','FontSize',14);
% Store High-resolution Image Suitable for use in Reports
print -f1 -r300 -dbmp shakerSortVisualisation.bmp