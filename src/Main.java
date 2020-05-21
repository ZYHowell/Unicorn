// import Parser.assemblyErrorListener;
import Parser.assemblyLexer;
import Parser.assemblyParser;

import Util.error;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;

import java.io.FileInputStream;
import java.io.InputStream;

public class Main {
    public static void main(String[] args) throws Exception{
        boolean doCodeGen = true, doOptimization = true;//, inTest = false;
        String name = "output.s";

        InputStream input = new FileInputStream(name);
        try {

            assemblyLexer lexer = new assemblyLexer(CharStreams.fromStream(input));
//            lexer.removeErrorListeners();
//            lexer.addErrorListener(new assemblyErrorListener());
            assemblyParser parser = new assemblyParser(new CommonTokenStream(lexer));
//            parser.removeErrorListeners();
//            parser.addErrorListener(new assemblyErrorListener());
            ParseTree parseTreeRoot = parser.file();
//            ASTBuilder astBuilder = new ASTBuilder();
//            ASTRoot = (rootNode)astBuilder.visit(parseTreeRoot);

        } catch (error er) {
            System.err.println(er.toString());
            throw new RuntimeException();
        }
    }
}
