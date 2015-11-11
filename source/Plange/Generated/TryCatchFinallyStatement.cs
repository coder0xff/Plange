using Parlex;

namespace Generated {
	public partial class TryCatchFinallyStatement : Production {
		public TryCatchFinallyStatement() : base("TryCatchFinallyStatement", false) { }
		public override void Start() {
			State5();
		}

		void State8() {
			Transition<FinallyBlock>(State2);
			Transition<CatchBlock>(State2);
			Transition<CatchBlock>(State7);
		}

		void State4() {
			Transition<Ws>(State3);
		}

		void State7() {
			Transition<Ws>(State8);
		}

		void State2() {
			Transition<Ws>(State6);
		}

		void State6() {
			Transition(";", State1);
		}

		void State5() {
			Transition("try", State4);
		}

		void State1() {
			Accept();
		}

		void State3() {
			Transition<BlockLiteral>(State7);
		}

	}
}
