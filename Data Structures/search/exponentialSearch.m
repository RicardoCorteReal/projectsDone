%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Title: Exponential Search Function
% Author: 
% Rev. Date: 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [numComparisons, targetIndex] = exponentialSearch(V, target)
numComparisons = 0;
arrayLength = length(V);
indexSearch = 1;
while (indexSearch < arrayLength && V(indexSearch) < target)
    indexSearch = indexSearch*2;
    numComparisons = numComparisons + 1;
end
indexMinium = min(indexSearch, arrayLength);
[numComparisons_binary, targetIndex_binary] = binarySearch(V(ceil(indexSearch/2):indexMinium), target);
targetIndex = indexSearch/2 + targetIndex_binary - 1;
numComparisons = numComparisons + numComparisons_binary;
end