%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Title: Interpolation Search Function
% Author: 
% Rev. Date: 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [numComparisons, targetIndex] = interpolationSearch(V, target)
numComparisons = 0;
arrayLength = length(V);
indexSearch = 1;
lowBound = 1;
highBound = arrayLength;
while (lowBound < highBound && target >= V(lowBound) && target <= V(highBound))
    numComparisons = numComparisons + 1;
    if lowBound == highBound
        if V(highBound) == target
            targetIndex = highBound;
            return;
        else
            targetIndex = -1;
            break;
        end
    end
    indexSearch  = lowBound + floor((((highBound - lowBound)/(V(highBound)-V(lowBound)))*(target - V(lowBound))));
    if V(indexSearch) == target
        targetIndex = indexSearch;
        break;
    elseif V(indexSearch) < target
        lowBound = indexSearch + 1; 
    else
        highBound = indexSearch - 1; 
    end
end
end
