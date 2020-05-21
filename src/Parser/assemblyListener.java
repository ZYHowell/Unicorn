// Generated from assembly.g4 by ANTLR 4.7.2
package Parser;
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link assemblyParser}.
 */
public interface assemblyListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link assemblyParser#file}.
	 * @param ctx the parse tree
	 */
	void enterFile(assemblyParser.FileContext ctx);
	/**
	 * Exit a parse tree produced by {@link assemblyParser#file}.
	 * @param ctx the parse tree
	 */
	void exitFile(assemblyParser.FileContext ctx);
	/**
	 * Enter a parse tree produced by {@link assemblyParser#line}.
	 * @param ctx the parse tree
	 */
	void enterLine(assemblyParser.LineContext ctx);
	/**
	 * Exit a parse tree produced by {@link assemblyParser#line}.
	 * @param ctx the parse tree
	 */
	void exitLine(assemblyParser.LineContext ctx);
	/**
	 * Enter a parse tree produced by {@link assemblyParser#inst}.
	 * @param ctx the parse tree
	 */
	void enterInst(assemblyParser.InstContext ctx);
	/**
	 * Exit a parse tree produced by {@link assemblyParser#inst}.
	 * @param ctx the parse tree
	 */
	void exitInst(assemblyParser.InstContext ctx);
	/**
	 * Enter a parse tree produced by {@link assemblyParser#rtype}.
	 * @param ctx the parse tree
	 */
	void enterRtype(assemblyParser.RtypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link assemblyParser#rtype}.
	 * @param ctx the parse tree
	 */
	void exitRtype(assemblyParser.RtypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link assemblyParser#itype}.
	 * @param ctx the parse tree
	 */
	void enterItype(assemblyParser.ItypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link assemblyParser#itype}.
	 * @param ctx the parse tree
	 */
	void exitItype(assemblyParser.ItypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link assemblyParser#stype}.
	 * @param ctx the parse tree
	 */
	void enterStype(assemblyParser.StypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link assemblyParser#stype}.
	 * @param ctx the parse tree
	 */
	void exitStype(assemblyParser.StypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link assemblyParser#btype}.
	 * @param ctx the parse tree
	 */
	void enterBtype(assemblyParser.BtypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link assemblyParser#btype}.
	 * @param ctx the parse tree
	 */
	void exitBtype(assemblyParser.BtypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link assemblyParser#utype}.
	 * @param ctx the parse tree
	 */
	void enterUtype(assemblyParser.UtypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link assemblyParser#utype}.
	 * @param ctx the parse tree
	 */
	void exitUtype(assemblyParser.UtypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link assemblyParser#jtype}.
	 * @param ctx the parse tree
	 */
	void enterJtype(assemblyParser.JtypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link assemblyParser#jtype}.
	 * @param ctx the parse tree
	 */
	void exitJtype(assemblyParser.JtypeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code mv}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 */
	void enterMv(assemblyParser.MvContext ctx);
	/**
	 * Exit a parse tree produced by the {@code mv}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 */
	void exitMv(assemblyParser.MvContext ctx);
	/**
	 * Enter a parse tree produced by the {@code li}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 */
	void enterLi(assemblyParser.LiContext ctx);
	/**
	 * Exit a parse tree produced by the {@code li}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 */
	void exitLi(assemblyParser.LiContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ret}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 */
	void enterRet(assemblyParser.RetContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ret}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 */
	void exitRet(assemblyParser.RetContext ctx);
	/**
	 * Enter a parse tree produced by the {@code jp}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 */
	void enterJp(assemblyParser.JpContext ctx);
	/**
	 * Exit a parse tree produced by the {@code jp}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 */
	void exitJp(assemblyParser.JpContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ld}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 */
	void enterLd(assemblyParser.LdContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ld}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 */
	void exitLd(assemblyParser.LdContext ctx);
	/**
	 * Enter a parse tree produced by the {@code la}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 */
	void enterLa(assemblyParser.LaContext ctx);
	/**
	 * Exit a parse tree produced by the {@code la}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 */
	void exitLa(assemblyParser.LaContext ctx);
	/**
	 * Enter a parse tree produced by the {@code call}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 */
	void enterCall(assemblyParser.CallContext ctx);
	/**
	 * Exit a parse tree produced by the {@code call}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 */
	void exitCall(assemblyParser.CallContext ctx);
	/**
	 * Enter a parse tree produced by the {@code sz}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 */
	void enterSz(assemblyParser.SzContext ctx);
	/**
	 * Exit a parse tree produced by the {@code sz}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 */
	void exitSz(assemblyParser.SzContext ctx);
	/**
	 * Enter a parse tree produced by the {@code bz}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 */
	void enterBz(assemblyParser.BzContext ctx);
	/**
	 * Exit a parse tree produced by the {@code bz}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 */
	void exitBz(assemblyParser.BzContext ctx);
	/**
	 * Enter a parse tree produced by the {@code section}
	 * labeled alternative in {@link assemblyParser#derictive}.
	 * @param ctx the parse tree
	 */
	void enterSection(assemblyParser.SectionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code section}
	 * labeled alternative in {@link assemblyParser#derictive}.
	 * @param ctx the parse tree
	 */
	void exitSection(assemblyParser.SectionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type}
	 * labeled alternative in {@link assemblyParser#derictive}.
	 * @param ctx the parse tree
	 */
	void enterType(assemblyParser.TypeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type}
	 * labeled alternative in {@link assemblyParser#derictive}.
	 * @param ctx the parse tree
	 */
	void exitType(assemblyParser.TypeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code align}
	 * labeled alternative in {@link assemblyParser#derictive}.
	 * @param ctx the parse tree
	 */
	void enterAlign(assemblyParser.AlignContext ctx);
	/**
	 * Exit a parse tree produced by the {@code align}
	 * labeled alternative in {@link assemblyParser#derictive}.
	 * @param ctx the parse tree
	 */
	void exitAlign(assemblyParser.AlignContext ctx);
	/**
	 * Enter a parse tree produced by the {@code size}
	 * labeled alternative in {@link assemblyParser#derictive}.
	 * @param ctx the parse tree
	 */
	void enterSize(assemblyParser.SizeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code size}
	 * labeled alternative in {@link assemblyParser#derictive}.
	 * @param ctx the parse tree
	 */
	void exitSize(assemblyParser.SizeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code asciz}
	 * labeled alternative in {@link assemblyParser#derictive}.
	 * @param ctx the parse tree
	 */
	void enterAsciz(assemblyParser.AscizContext ctx);
	/**
	 * Exit a parse tree produced by the {@code asciz}
	 * labeled alternative in {@link assemblyParser#derictive}.
	 * @param ctx the parse tree
	 */
	void exitAsciz(assemblyParser.AscizContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ignore}
	 * labeled alternative in {@link assemblyParser#derictive}.
	 * @param ctx the parse tree
	 */
	void enterIgnore(assemblyParser.IgnoreContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ignore}
	 * labeled alternative in {@link assemblyParser#derictive}.
	 * @param ctx the parse tree
	 */
	void exitIgnore(assemblyParser.IgnoreContext ctx);
}