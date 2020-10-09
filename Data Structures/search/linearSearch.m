%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Title: Linear Search Function
% Author: 
% Rev. Date:
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [numComparisons, currentIndex] = linearSearch(V, target)
numComparisons = 0;
for currentIndex=1:length(V)
    numComparisons = numComparisons + 1;
    if(V(currentIndex) == target)
        break;
    end % end if
end % end for
if(V(currentIndex)~=target)
    currentIndex = -1;
end % end if
end % end function