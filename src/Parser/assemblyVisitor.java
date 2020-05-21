// Generated from assembly.g4 by ANTLR 4.7.2
package Parser;
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link assemblyParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface assemblyVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link assemblyParser#file}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFile(assemblyParser.FileContext ctx);
	/**
	 * Visit a parse tree produced by {@link assemblyParser#line}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLine(assemblyParser.LineContext ctx);
	/**
	 * Visit a parse tree produced by {@link assemblyParser#inst}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInst(assemblyParser.InstContext ctx);
	/**
	 * Visit a parse tree produced by {@link assemblyParser#rtype}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRtype(assemblyParser.RtypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link assemblyParser#itype}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitItype(assemblyParser.ItypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link assemblyParser#stype}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStype(assemblyParser.StypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link assemblyParser#btype}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBtype(assemblyParser.BtypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link assemblyParser#utype}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitUtype(assemblyParser.UtypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link assemblyParser#jtype}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitJtype(assemblyParser.JtypeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code mv}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMv(assemblyParser.MvContext ctx);
	/**
	 * Visit a parse tree produced by the {@code li}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLi(assemblyParser.LiContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ret}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRet(assemblyParser.RetContext ctx);
	/**
	 * Visit a parse tree produced by the {@code jp}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitJp(assemblyParser.JpContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ld}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLd(assemblyParser.LdContext ctx);
	/**
	 * Visit a parse tree produced by the {@code la}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLa(assemblyParser.LaContext ctx);
	/**
	 * Visit a parse tree produced by the {@code call}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCall(assemblyParser.CallContext ctx);
	/**
	 * Visit a parse tree produced by the {@code sz}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSz(assemblyParser.SzContext ctx);
	/**
	 * Visit a parse tree produced by the {@code bz}
	 * labeled alternative in {@link assemblyParser#pseudoInst}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBz(assemblyParser.BzContext ctx);
	/**
	 * Visit a parse tree produced by the {@code section}
	 * labeled alternative in {@link assemblyParser#derictive}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSection(assemblyParser.SectionContext ctx);
	/**
	 * Visit a parse tree produced by the {@code type}
	 * labeled alternative in {@link assemblyParser#derictive}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitType(assemblyParser.TypeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code align}
	 * labeled alternative in {@link assemblyParser#derictive}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAlign(assemblyParser.AlignContext ctx);
	/**
	 * Visit a parse tree produced by the {@code size}
	 * labeled alternative in {@link assemblyParser#derictive}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSize(assemblyParser.SizeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code asciz}
	 * labeled alternative in {@link assemblyParser#derictive}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAsciz(assemblyParser.AscizContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ignore}
	 * labeled alternative in {@link assemblyParser#derictive}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIgnore(assemblyParser.IgnoreContext ctx);
}