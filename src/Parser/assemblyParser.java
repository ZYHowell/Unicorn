// Generated from assembly.g4 by ANTLR 4.7.2
package Parser;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class assemblyParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.7.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		T__17=18, T__18=19, T__19=20, T__20=21, T__21=22, T__22=23, T__23=24, 
		T__24=25, T__25=26, IgnoreDirective=27, Section=28, Type=29, Rop=30, Iop=31, 
		Sop=32, Bop=33, Uop=34, Jop=35, Reg=36, Symbol=37, Label=38, StringLiteral=39, 
		Imm=40, Relocation=41, Integer=42, DecimalInteger=43, Whitespace=44, Newline=45, 
		LineComment=46;
	public static final int
		RULE_file = 0, RULE_line = 1, RULE_inst = 2, RULE_rtype = 3, RULE_itype = 4, 
		RULE_stype = 5, RULE_btype = 6, RULE_utype = 7, RULE_jtype = 8, RULE_pseudoInst = 9, 
		RULE_derictive = 10;
	private static String[] makeRuleNames() {
		return new String[] {
			"file", "line", "inst", "rtype", "itype", "stype", "btype", "utype", 
			"jtype", "pseudoInst", "derictive"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "','", "'('", "')'", "'mv'", "'li'", "'ret'", "'j'", "'lb'", "'lh'", 
			"'lw'", "'la'", "'call'", "'seqz'", "'snez'", "'sgtz'", "'sltz'", "'beqz'", 
			"'bnez'", "'bgtz'", "'bltz'", "'blez'", "'.type'", "'.p2align'", "'.align'", 
			"'.size'", "'.asciz'", null, null, null, null, null, null, null, null, 
			"'jal'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, "IgnoreDirective", "Section", "Type", "Rop", "Iop", 
			"Sop", "Bop", "Uop", "Jop", "Reg", "Symbol", "Label", "StringLiteral", 
			"Imm", "Relocation", "Integer", "DecimalInteger", "Whitespace", "Newline", 
			"LineComment"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "assembly.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public assemblyParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class FileContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(assemblyParser.EOF, 0); }
		public List<LineContext> line() {
			return getRuleContexts(LineContext.class);
		}
		public LineContext line(int i) {
			return getRuleContext(LineContext.class,i);
		}
		public FileContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_file; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterFile(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitFile(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitFile(this);
			else return visitor.visitChildren(this);
		}
	}

	public final FileContext file() throws RecognitionException {
		FileContext _localctx = new FileContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_file);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(25);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__3) | (1L << T__4) | (1L << T__5) | (1L << T__6) | (1L << T__7) | (1L << T__8) | (1L << T__9) | (1L << T__10) | (1L << T__11) | (1L << T__12) | (1L << T__13) | (1L << T__14) | (1L << T__15) | (1L << T__16) | (1L << T__17) | (1L << T__18) | (1L << T__19) | (1L << T__20) | (1L << T__21) | (1L << T__22) | (1L << T__23) | (1L << T__24) | (1L << T__25) | (1L << IgnoreDirective) | (1L << Section) | (1L << Rop) | (1L << Iop) | (1L << Sop) | (1L << Bop) | (1L << Uop) | (1L << Jop))) != 0)) {
				{
				{
				setState(22);
				line();
				}
				}
				setState(27);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(28);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LineContext extends ParserRuleContext {
		public InstContext inst() {
			return getRuleContext(InstContext.class,0);
		}
		public PseudoInstContext pseudoInst() {
			return getRuleContext(PseudoInstContext.class,0);
		}
		public DerictiveContext derictive() {
			return getRuleContext(DerictiveContext.class,0);
		}
		public LineContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_line; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterLine(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitLine(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitLine(this);
			else return visitor.visitChildren(this);
		}
	}

	public final LineContext line() throws RecognitionException {
		LineContext _localctx = new LineContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_line);
		try {
			setState(33);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Rop:
			case Iop:
			case Sop:
			case Bop:
			case Uop:
			case Jop:
				enterOuterAlt(_localctx, 1);
				{
				setState(30);
				inst();
				}
				break;
			case T__3:
			case T__4:
			case T__5:
			case T__6:
			case T__7:
			case T__8:
			case T__9:
			case T__10:
			case T__11:
			case T__12:
			case T__13:
			case T__14:
			case T__15:
			case T__16:
			case T__17:
			case T__18:
			case T__19:
			case T__20:
				enterOuterAlt(_localctx, 2);
				{
				setState(31);
				pseudoInst();
				}
				break;
			case T__21:
			case T__22:
			case T__23:
			case T__24:
			case T__25:
			case IgnoreDirective:
			case Section:
				enterOuterAlt(_localctx, 3);
				{
				setState(32);
				derictive();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class InstContext extends ParserRuleContext {
		public RtypeContext rtype() {
			return getRuleContext(RtypeContext.class,0);
		}
		public ItypeContext itype() {
			return getRuleContext(ItypeContext.class,0);
		}
		public StypeContext stype() {
			return getRuleContext(StypeContext.class,0);
		}
		public BtypeContext btype() {
			return getRuleContext(BtypeContext.class,0);
		}
		public UtypeContext utype() {
			return getRuleContext(UtypeContext.class,0);
		}
		public JtypeContext jtype() {
			return getRuleContext(JtypeContext.class,0);
		}
		public InstContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_inst; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterInst(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitInst(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitInst(this);
			else return visitor.visitChildren(this);
		}
	}

	public final InstContext inst() throws RecognitionException {
		InstContext _localctx = new InstContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_inst);
		try {
			setState(41);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Rop:
				enterOuterAlt(_localctx, 1);
				{
				setState(35);
				rtype();
				}
				break;
			case Iop:
				enterOuterAlt(_localctx, 2);
				{
				setState(36);
				itype();
				}
				break;
			case Sop:
				enterOuterAlt(_localctx, 3);
				{
				setState(37);
				stype();
				}
				break;
			case Bop:
				enterOuterAlt(_localctx, 4);
				{
				setState(38);
				btype();
				}
				break;
			case Uop:
				enterOuterAlt(_localctx, 5);
				{
				setState(39);
				utype();
				}
				break;
			case Jop:
				enterOuterAlt(_localctx, 6);
				{
				setState(40);
				jtype();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class RtypeContext extends ParserRuleContext {
		public Token rd;
		public Token src1;
		public Token src2;
		public TerminalNode Rop() { return getToken(assemblyParser.Rop, 0); }
		public List<TerminalNode> Reg() { return getTokens(assemblyParser.Reg); }
		public TerminalNode Reg(int i) {
			return getToken(assemblyParser.Reg, i);
		}
		public RtypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rtype; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterRtype(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitRtype(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitRtype(this);
			else return visitor.visitChildren(this);
		}
	}

	public final RtypeContext rtype() throws RecognitionException {
		RtypeContext _localctx = new RtypeContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_rtype);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(43);
			match(Rop);
			setState(44);
			((RtypeContext)_localctx).rd = match(Reg);
			setState(45);
			match(T__0);
			setState(46);
			((RtypeContext)_localctx).src1 = match(Reg);
			setState(47);
			match(T__0);
			setState(48);
			((RtypeContext)_localctx).src2 = match(Reg);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ItypeContext extends ParserRuleContext {
		public Token rd;
		public Token src;
		public Token imm;
		public TerminalNode Iop() { return getToken(assemblyParser.Iop, 0); }
		public List<TerminalNode> Reg() { return getTokens(assemblyParser.Reg); }
		public TerminalNode Reg(int i) {
			return getToken(assemblyParser.Reg, i);
		}
		public TerminalNode Imm() { return getToken(assemblyParser.Imm, 0); }
		public ItypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_itype; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterItype(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitItype(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitItype(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ItypeContext itype() throws RecognitionException {
		ItypeContext _localctx = new ItypeContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_itype);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(50);
			match(Iop);
			setState(51);
			((ItypeContext)_localctx).rd = match(Reg);
			setState(52);
			match(T__0);
			setState(53);
			((ItypeContext)_localctx).src = match(Reg);
			setState(54);
			match(T__0);
			setState(55);
			((ItypeContext)_localctx).imm = match(Imm);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StypeContext extends ParserRuleContext {
		public Token value;
		public Token offset;
		public Token addr;
		public TerminalNode Sop() { return getToken(assemblyParser.Sop, 0); }
		public List<TerminalNode> Reg() { return getTokens(assemblyParser.Reg); }
		public TerminalNode Reg(int i) {
			return getToken(assemblyParser.Reg, i);
		}
		public TerminalNode Integer() { return getToken(assemblyParser.Integer, 0); }
		public StypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stype; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterStype(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitStype(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitStype(this);
			else return visitor.visitChildren(this);
		}
	}

	public final StypeContext stype() throws RecognitionException {
		StypeContext _localctx = new StypeContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_stype);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(57);
			match(Sop);
			setState(58);
			((StypeContext)_localctx).value = match(Reg);
			setState(59);
			match(T__0);
			setState(60);
			((StypeContext)_localctx).offset = match(Integer);
			setState(61);
			match(T__1);
			setState(62);
			((StypeContext)_localctx).addr = match(Reg);
			setState(63);
			match(T__2);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BtypeContext extends ParserRuleContext {
		public Token src1;
		public Token src2;
		public Token label;
		public TerminalNode Bop() { return getToken(assemblyParser.Bop, 0); }
		public List<TerminalNode> Reg() { return getTokens(assemblyParser.Reg); }
		public TerminalNode Reg(int i) {
			return getToken(assemblyParser.Reg, i);
		}
		public TerminalNode Label() { return getToken(assemblyParser.Label, 0); }
		public BtypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_btype; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterBtype(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitBtype(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitBtype(this);
			else return visitor.visitChildren(this);
		}
	}

	public final BtypeContext btype() throws RecognitionException {
		BtypeContext _localctx = new BtypeContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_btype);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(65);
			match(Bop);
			setState(66);
			((BtypeContext)_localctx).src1 = match(Reg);
			setState(67);
			match(T__0);
			setState(68);
			((BtypeContext)_localctx).src2 = match(Reg);
			setState(69);
			match(T__0);
			setState(70);
			((BtypeContext)_localctx).label = match(Label);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class UtypeContext extends ParserRuleContext {
		public Token rd;
		public Token imm;
		public TerminalNode Uop() { return getToken(assemblyParser.Uop, 0); }
		public TerminalNode Reg() { return getToken(assemblyParser.Reg, 0); }
		public TerminalNode Imm() { return getToken(assemblyParser.Imm, 0); }
		public UtypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_utype; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterUtype(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitUtype(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitUtype(this);
			else return visitor.visitChildren(this);
		}
	}

	public final UtypeContext utype() throws RecognitionException {
		UtypeContext _localctx = new UtypeContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_utype);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(72);
			match(Uop);
			setState(73);
			((UtypeContext)_localctx).rd = match(Reg);
			setState(74);
			match(T__0);
			setState(75);
			((UtypeContext)_localctx).imm = match(Imm);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class JtypeContext extends ParserRuleContext {
		public Token rd;
		public Token imm;
		public TerminalNode Jop() { return getToken(assemblyParser.Jop, 0); }
		public TerminalNode Reg() { return getToken(assemblyParser.Reg, 0); }
		public TerminalNode Imm() { return getToken(assemblyParser.Imm, 0); }
		public JtypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_jtype; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterJtype(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitJtype(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitJtype(this);
			else return visitor.visitChildren(this);
		}
	}

	public final JtypeContext jtype() throws RecognitionException {
		JtypeContext _localctx = new JtypeContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_jtype);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(77);
			match(Jop);
			setState(78);
			((JtypeContext)_localctx).rd = match(Reg);
			setState(79);
			match(T__0);
			setState(80);
			((JtypeContext)_localctx).imm = match(Imm);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class PseudoInstContext extends ParserRuleContext {
		public PseudoInstContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_pseudoInst; }
	 
		public PseudoInstContext() { }
		public void copyFrom(PseudoInstContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class RetContext extends PseudoInstContext {
		public RetContext(PseudoInstContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterRet(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitRet(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitRet(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class CallContext extends PseudoInstContext {
		public TerminalNode Symbol() { return getToken(assemblyParser.Symbol, 0); }
		public CallContext(PseudoInstContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterCall(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitCall(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitCall(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class LaContext extends PseudoInstContext {
		public Token rd;
		public Token src;
		public TerminalNode Reg() { return getToken(assemblyParser.Reg, 0); }
		public TerminalNode Symbol() { return getToken(assemblyParser.Symbol, 0); }
		public LaContext(PseudoInstContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterLa(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitLa(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitLa(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class JpContext extends PseudoInstContext {
		public Token label;
		public TerminalNode Label() { return getToken(assemblyParser.Label, 0); }
		public JpContext(PseudoInstContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterJp(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitJp(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitJp(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class SzContext extends PseudoInstContext {
		public Token rd;
		public Token src;
		public List<TerminalNode> Reg() { return getTokens(assemblyParser.Reg); }
		public TerminalNode Reg(int i) {
			return getToken(assemblyParser.Reg, i);
		}
		public SzContext(PseudoInstContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterSz(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitSz(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitSz(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class LdContext extends PseudoInstContext {
		public Token rd;
		public Token src;
		public TerminalNode Reg() { return getToken(assemblyParser.Reg, 0); }
		public TerminalNode Symbol() { return getToken(assemblyParser.Symbol, 0); }
		public LdContext(PseudoInstContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterLd(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitLd(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitLd(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class BzContext extends PseudoInstContext {
		public Token src;
		public Token label;
		public TerminalNode Reg() { return getToken(assemblyParser.Reg, 0); }
		public TerminalNode Label() { return getToken(assemblyParser.Label, 0); }
		public BzContext(PseudoInstContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterBz(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitBz(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitBz(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class MvContext extends PseudoInstContext {
		public Token rd;
		public Token src;
		public List<TerminalNode> Reg() { return getTokens(assemblyParser.Reg); }
		public TerminalNode Reg(int i) {
			return getToken(assemblyParser.Reg, i);
		}
		public MvContext(PseudoInstContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterMv(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitMv(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitMv(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class LiContext extends PseudoInstContext {
		public Token rd;
		public Token src;
		public TerminalNode Reg() { return getToken(assemblyParser.Reg, 0); }
		public TerminalNode Imm() { return getToken(assemblyParser.Imm, 0); }
		public LiContext(PseudoInstContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterLi(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitLi(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitLi(this);
			else return visitor.visitChildren(this);
		}
	}

	public final PseudoInstContext pseudoInst() throws RecognitionException {
		PseudoInstContext _localctx = new PseudoInstContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_pseudoInst);
		int _la;
		try {
			setState(111);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__3:
				_localctx = new MvContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(82);
				match(T__3);
				setState(83);
				((MvContext)_localctx).rd = match(Reg);
				setState(84);
				match(T__0);
				setState(85);
				((MvContext)_localctx).src = match(Reg);
				}
				break;
			case T__4:
				_localctx = new LiContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(86);
				match(T__4);
				setState(87);
				((LiContext)_localctx).rd = match(Reg);
				setState(88);
				match(T__0);
				setState(89);
				((LiContext)_localctx).src = match(Imm);
				}
				break;
			case T__5:
				_localctx = new RetContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(90);
				match(T__5);
				}
				break;
			case T__6:
				_localctx = new JpContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(91);
				match(T__6);
				setState(92);
				((JpContext)_localctx).label = match(Label);
				}
				break;
			case T__7:
			case T__8:
			case T__9:
				_localctx = new LdContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(93);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__7) | (1L << T__8) | (1L << T__9))) != 0)) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(94);
				((LdContext)_localctx).rd = match(Reg);
				setState(95);
				match(T__0);
				setState(96);
				((LdContext)_localctx).src = match(Symbol);
				}
				break;
			case T__10:
				_localctx = new LaContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(97);
				match(T__10);
				setState(98);
				((LaContext)_localctx).rd = match(Reg);
				setState(99);
				match(T__0);
				setState(100);
				((LaContext)_localctx).src = match(Symbol);
				}
				break;
			case T__11:
				_localctx = new CallContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(101);
				match(T__11);
				setState(102);
				match(Symbol);
				}
				break;
			case T__12:
			case T__13:
			case T__14:
			case T__15:
				_localctx = new SzContext(_localctx);
				enterOuterAlt(_localctx, 8);
				{
				setState(103);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__12) | (1L << T__13) | (1L << T__14) | (1L << T__15))) != 0)) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(104);
				((SzContext)_localctx).rd = match(Reg);
				setState(105);
				match(T__0);
				setState(106);
				((SzContext)_localctx).src = match(Reg);
				}
				break;
			case T__16:
			case T__17:
			case T__18:
			case T__19:
			case T__20:
				_localctx = new BzContext(_localctx);
				enterOuterAlt(_localctx, 9);
				{
				setState(107);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__16) | (1L << T__17) | (1L << T__18) | (1L << T__19) | (1L << T__20))) != 0)) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(108);
				((BzContext)_localctx).src = match(Reg);
				setState(109);
				match(T__0);
				setState(110);
				((BzContext)_localctx).label = match(Label);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DerictiveContext extends ParserRuleContext {
		public DerictiveContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_derictive; }
	 
		public DerictiveContext() { }
		public void copyFrom(DerictiveContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class SizeContext extends DerictiveContext {
		public TerminalNode Integer() { return getToken(assemblyParser.Integer, 0); }
		public SizeContext(DerictiveContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterSize(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitSize(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitSize(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class IgnoreContext extends DerictiveContext {
		public TerminalNode IgnoreDirective() { return getToken(assemblyParser.IgnoreDirective, 0); }
		public IgnoreContext(DerictiveContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterIgnore(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitIgnore(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitIgnore(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class SectionContext extends DerictiveContext {
		public TerminalNode Section() { return getToken(assemblyParser.Section, 0); }
		public SectionContext(DerictiveContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterSection(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitSection(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitSection(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class TypeContext extends DerictiveContext {
		public Token symbol;
		public TerminalNode Type() { return getToken(assemblyParser.Type, 0); }
		public TerminalNode Symbol() { return getToken(assemblyParser.Symbol, 0); }
		public TypeContext(DerictiveContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitType(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitType(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class AlignContext extends DerictiveContext {
		public TerminalNode Integer() { return getToken(assemblyParser.Integer, 0); }
		public AlignContext(DerictiveContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterAlign(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitAlign(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitAlign(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class AscizContext extends DerictiveContext {
		public TerminalNode StringLiteral() { return getToken(assemblyParser.StringLiteral, 0); }
		public AscizContext(DerictiveContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).enterAsciz(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof assemblyListener ) ((assemblyListener)listener).exitAsciz(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof assemblyVisitor ) return ((assemblyVisitor<? extends T>)visitor).visitAsciz(this);
			else return visitor.visitChildren(this);
		}
	}

	public final DerictiveContext derictive() throws RecognitionException {
		DerictiveContext _localctx = new DerictiveContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_derictive);
		int _la;
		try {
			setState(125);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Section:
				_localctx = new SectionContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(113);
				match(Section);
				}
				break;
			case T__21:
				_localctx = new TypeContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(114);
				match(T__21);
				setState(115);
				((TypeContext)_localctx).symbol = match(Symbol);
				setState(116);
				match(T__0);
				setState(117);
				match(Type);
				}
				break;
			case T__22:
			case T__23:
				_localctx = new AlignContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(118);
				_la = _input.LA(1);
				if ( !(_la==T__22 || _la==T__23) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(119);
				match(Integer);
				}
				break;
			case T__24:
				_localctx = new SizeContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(120);
				match(T__24);
				setState(121);
				match(Integer);
				}
				break;
			case T__25:
				_localctx = new AscizContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(122);
				match(T__25);
				setState(123);
				match(StringLiteral);
				}
				break;
			case IgnoreDirective:
				_localctx = new IgnoreContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(124);
				match(IgnoreDirective);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\60\u0082\4\2\t\2"+
		"\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\3\2\7\2\32\n\2\f\2\16\2\35\13\2\3\2\3\2\3\3\3\3\3\3\5\3"+
		"$\n\3\3\4\3\4\3\4\3\4\3\4\3\4\5\4,\n\4\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\6"+
		"\3\6\3\6\3\6\3\6\3\6\3\6\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\b\3\b\3\b\3"+
		"\b\3\b\3\b\3\b\3\t\3\t\3\t\3\t\3\t\3\n\3\n\3\n\3\n\3\n\3\13\3\13\3\13"+
		"\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13"+
		"\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\5\13r\n\13"+
		"\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\5\f\u0080\n\f\3\f\2\2"+
		"\r\2\4\6\b\n\f\16\20\22\24\26\2\6\3\2\n\f\3\2\17\22\3\2\23\27\3\2\31\32"+
		"\2\u008b\2\33\3\2\2\2\4#\3\2\2\2\6+\3\2\2\2\b-\3\2\2\2\n\64\3\2\2\2\f"+
		";\3\2\2\2\16C\3\2\2\2\20J\3\2\2\2\22O\3\2\2\2\24q\3\2\2\2\26\177\3\2\2"+
		"\2\30\32\5\4\3\2\31\30\3\2\2\2\32\35\3\2\2\2\33\31\3\2\2\2\33\34\3\2\2"+
		"\2\34\36\3\2\2\2\35\33\3\2\2\2\36\37\7\2\2\3\37\3\3\2\2\2 $\5\6\4\2!$"+
		"\5\24\13\2\"$\5\26\f\2# \3\2\2\2#!\3\2\2\2#\"\3\2\2\2$\5\3\2\2\2%,\5\b"+
		"\5\2&,\5\n\6\2\',\5\f\7\2(,\5\16\b\2),\5\20\t\2*,\5\22\n\2+%\3\2\2\2+"+
		"&\3\2\2\2+\'\3\2\2\2+(\3\2\2\2+)\3\2\2\2+*\3\2\2\2,\7\3\2\2\2-.\7 \2\2"+
		"./\7&\2\2/\60\7\3\2\2\60\61\7&\2\2\61\62\7\3\2\2\62\63\7&\2\2\63\t\3\2"+
		"\2\2\64\65\7!\2\2\65\66\7&\2\2\66\67\7\3\2\2\678\7&\2\289\7\3\2\29:\7"+
		"*\2\2:\13\3\2\2\2;<\7\"\2\2<=\7&\2\2=>\7\3\2\2>?\7,\2\2?@\7\4\2\2@A\7"+
		"&\2\2AB\7\5\2\2B\r\3\2\2\2CD\7#\2\2DE\7&\2\2EF\7\3\2\2FG\7&\2\2GH\7\3"+
		"\2\2HI\7(\2\2I\17\3\2\2\2JK\7$\2\2KL\7&\2\2LM\7\3\2\2MN\7*\2\2N\21\3\2"+
		"\2\2OP\7%\2\2PQ\7&\2\2QR\7\3\2\2RS\7*\2\2S\23\3\2\2\2TU\7\6\2\2UV\7&\2"+
		"\2VW\7\3\2\2Wr\7&\2\2XY\7\7\2\2YZ\7&\2\2Z[\7\3\2\2[r\7*\2\2\\r\7\b\2\2"+
		"]^\7\t\2\2^r\7(\2\2_`\t\2\2\2`a\7&\2\2ab\7\3\2\2br\7\'\2\2cd\7\r\2\2d"+
		"e\7&\2\2ef\7\3\2\2fr\7\'\2\2gh\7\16\2\2hr\7\'\2\2ij\t\3\2\2jk\7&\2\2k"+
		"l\7\3\2\2lr\7&\2\2mn\t\4\2\2no\7&\2\2op\7\3\2\2pr\7(\2\2qT\3\2\2\2qX\3"+
		"\2\2\2q\\\3\2\2\2q]\3\2\2\2q_\3\2\2\2qc\3\2\2\2qg\3\2\2\2qi\3\2\2\2qm"+
		"\3\2\2\2r\25\3\2\2\2s\u0080\7\36\2\2tu\7\30\2\2uv\7\'\2\2vw\7\3\2\2w\u0080"+
		"\7\37\2\2xy\t\5\2\2y\u0080\7,\2\2z{\7\33\2\2{\u0080\7,\2\2|}\7\34\2\2"+
		"}\u0080\7)\2\2~\u0080\7\35\2\2\177s\3\2\2\2\177t\3\2\2\2\177x\3\2\2\2"+
		"\177z\3\2\2\2\177|\3\2\2\2\177~\3\2\2\2\u0080\27\3\2\2\2\7\33#+q\177";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}