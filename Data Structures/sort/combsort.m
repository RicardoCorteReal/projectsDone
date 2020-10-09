%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TItle: Comb Sort Algorithm Visualisation for Reversed Arrays
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
shrink = 1.3; % shrink > 1

gap = N;
isSorted = false;
swapped = true;
while ((gap > 1) || (~isSorted == true))
    gap = max(floor(gap/shrink),1);  % Update gap
    currentPos = 1;  % Bubble sort with given gap
    isSorted = true;
    while ((currentPos + gap) <= N)
        if (V(currentPos) > V(currentPos + gap))
            temp = V(currentPos);
            V(currentPos) = V(currentPos+gap);
            V(currentPos+gap) = temp;
            isSorted = false;
            arrayState(1:N,changeNumber) = V;
            changeNumber = changeNumber + 1;
        end % if
        currentPos = currentPos + 1;
    end % while
end


figure;
imagesc(arrayState);
axis square;
colormap jet;
ylabel('Element Number','FontSize',14);
xlabel('Array State','FontSize',14);
% Store High-resolution Image Suitable for use in Reports
print -f1 -r300 -dbmp combSortVisualisation.bmp