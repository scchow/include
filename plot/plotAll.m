function plotAll()
close all
numAgents = [150,200];
legendLoc = 'EastOutside';
for i=1:size(numAgents, 2)
    plot_nonadaptive(numAgents(i), legendLoc);
    plot_temp(numAgents(i), legendLoc);
    plot_numLearning(numAgents(i), legendLoc);
    close all
end