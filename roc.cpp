#include "roc.h"

ROC::ROC()
{

}



roc_data ROC::calculate_roc_curve_total(vector<vector<double>> predictions, vector<string> labels, int n_points)
{
    int n_examples = predictions[0].size();
    unordered_map<string, int> label_to_index;
    vector<int> label_indices(n_examples);
    int label_index = 0;
    for (int i = 0; i < n_examples; i++) {
        if (label_to_index.find(labels[i]) == label_to_index.end()) {
            label_to_index[labels[i]] = label_index;
            label_index++;
        }
        label_indices[i] = label_to_index[labels[i]];
    }
    vector<pair<double, int>> score_label_pairs(n_examples);
    for (int i = 0; i < n_examples; i++) {
        double max_score = predictions[0][i];
        int max_label = 0;
        for (int j = 1; j < predictions.size(); j++) {
            if (predictions[j][i] > max_score) {
                max_score = predictions[j][i];
                max_label = j;
            }
        }
        score_label_pairs[i] = make_pair(max_score, (label_indices[i] == max_label) ? 1 : 0);
    }
    sort(score_label_pairs.begin(), score_label_pairs.end(), greater<pair<double, int>>());
    roc_data roc_curve;
    roc_curve.true_positive_counts.resize(n_points);
    roc_curve.true_negative_counts.resize(n_points);
    roc_curve.false_positive_counts.resize(n_points);
    roc_curve.false_negative_counts.resize(n_points);
    for (int j = 0; j < n_points; j++) {
        double threshold = (j == 0) ? score_label_pairs[0].first + 1 : score_label_pairs[(j * n_examples) / n_points - 1].first;
        int true_positive_count = 0;
        int true_negative_count = 0;
        int false_positive_count = 0;
        int false_negative_count = 0;
        for (int k = 0; k < n_examples; k++) {
            double score = score_label_pairs[k].first;
            int label = score_label_pairs[k].second;
            if (score >= threshold) {
                if (label == 1) {
                    true_positive_count++;
                } else {
                    false_positive_count++;
                }
            } else {
                if (label == 1) {
                    false_negative_count++;
                } else {
                    true_negative_count++;
                }
            }
        }
        roc_curve.threshold = threshold;
        roc_curve.true_positive_counts[j] = true_positive_count;
        roc_curve.true_negative_counts[j] = true_negative_count;
        roc_curve.false_positive_counts[j] = false_positive_count;
        roc_curve.false_negative_counts[j] = false_negative_count;
    }
    return roc_curve;
}





void ROC::draw_roc_curve(Mat& img, roc_data roc_curve)
{
    int n_points = roc_curve.true_positive_counts.size();
    vector<double> tpr(n_points);
    vector<double> fpr(n_points);

    for (int j = 0; j < n_points; j++) {
        tpr[j] = roc_curve.true_positive_counts[j] / (double)(roc_curve.true_positive_counts[j] + roc_curve.false_negative_counts[j]);
        fpr[j] = roc_curve.false_positive_counts[j] / (double)(roc_curve.false_positive_counts[j] + roc_curve.true_negative_counts[j]);
    }

    vector<Point> curve_points(n_points);

    for (int j = 0; j < n_points; j++) {
        curve_points[j] = Point(img.cols * fpr[j], img.rows * (1 - tpr[j]));
    }

    polylines(img, curve_points, false, Scalar(255, 0, 0), 2);
}
