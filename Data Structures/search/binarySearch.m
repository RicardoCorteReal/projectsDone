%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Title: Binary Search Function
% Author: 
% Rev. Date: 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [numComparisons, targetIndex] = binarySearch(V, target)
numComparisons = 0;
arrayLength = length(V);
indexStart = 1;
indexEnd = length(V);
while(indexStart <= indexEnd)
    indexMiddle = floor((indexStart+indexEnd)/2);
    numComparisons = numComparisons + 1;
    if(V(indexMiddle) == target)
        targetIndex = indexMiddle;
        break;
    elseif(V(indexMiddle) < target)
        indexStart = indexMiddle + 1;
    else
        indexEnd = indexMiddle - 1;
    end % end if
end % end while
if(V(indexMiddle)~=target)
    targetIndex = -1;
end % end if
end % end function