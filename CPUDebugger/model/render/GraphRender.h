#include <graphviz/gvc.h>

#include <QFile>
#include <QTextStream>

void draw_rb()
{
    GVC_t *gvc = gvContext();

    // Create a simple digraph
    Agraph_t *g = agopen("g", Agdirected, 0);
    Agnode_t *n = agnode(g, "n", 1);
    Agnode_t *m = agnode(g, "m", 1);
    Agedge_t *e = agedge(g, n, m, 0, 1);

    // Set an attribute - in this case one that affects the visible rendering
    agsafeset(n, "color", "red", "");

    // Just write the graph without layout
//    agwrite(g, stdout);
    // Use the directed graph layout engine
    gvLayout(gvc, g, "dot");

    // Output in .dot format
    gvRenderFilename(gvc, g, "svg", "E:/dot.svg");

    gvFreeLayout(gvc, g);

    agclose(g);
}
