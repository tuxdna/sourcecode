package org.tuxdna.ml;

import java.io.File;

import org.apache.mahout.cf.taste.common.TasteException;
import org.apache.mahout.cf.taste.eval.RecommenderBuilder;
import org.apache.mahout.cf.taste.eval.RecommenderEvaluator;
import org.apache.mahout.cf.taste.example.grouplens.GroupLensDataModel;
import org.apache.mahout.cf.taste.impl.eval.AverageAbsoluteDifferenceRecommenderEvaluator;
import org.apache.mahout.cf.taste.impl.recommender.knn.KnnItemBasedRecommender;
import org.apache.mahout.cf.taste.impl.recommender.knn.NonNegativeQuadraticOptimizer;
import org.apache.mahout.cf.taste.impl.recommender.knn.Optimizer;
import org.apache.mahout.cf.taste.impl.similarity.LogLikelihoodSimilarity;
import org.apache.mahout.cf.taste.model.DataModel;
import org.apache.mahout.cf.taste.recommender.Recommender;
import org.apache.mahout.cf.taste.similarity.ItemSimilarity;

@SuppressWarnings("deprecation")
public class LinearInterpolationRecommenderExample {

	public static void main(String[] args) throws Exception {
		if (args.length < 1) {
			System.out.println("Input File path not given");
			System.exit(-1);
		}
		String inputFilePath = args[0];
		File inputFile = new File(inputFilePath);
		if (!inputFile.exists()) {
			System.out.println("Input file doesn't exist!: " + inputFilePath);
			System.exit(-1);
		}

		DataModel model = new GroupLensDataModel(inputFile);

		RecommenderEvaluator recEvaluator = new AverageAbsoluteDifferenceRecommenderEvaluator();

		RecommenderBuilder recBuilder = new RecommenderBuilder() {

			public Recommender buildRecommender(DataModel model)
					throws TasteException {
				ItemSimilarity similarity = new LogLikelihoodSimilarity(model);
				Optimizer optimizer = new NonNegativeQuadraticOptimizer();
				Recommender recommender = new KnnItemBasedRecommender(model,
						similarity, optimizer, 10);
				return recommender;
			}
		};

		double score = recEvaluator.evaluate(recBuilder, null, model, 0.9, 0.1);
		System.out.println(score);
	}
}
