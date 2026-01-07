package com.example.demo.services.parser_standard_method_expression;

import org.springframework.expression.Expression;
import org.springframework.expression.ExpressionParser;
import org.springframework.expression.spel.standard.SpelExpressionParser;
import org.springframework.expression.spel.support.StandardEvaluationContext;
import org.springframework.stereotype.Component;

@Component
public class ExpressionParserService {
    public void calculatorByExpressionParser() {
        ExpressionParser parser = new SpelExpressionParser();
        Expression expression = parser.parseExpression("100 * 2 + 200");
        Integer result = expression.getValue(Integer.class);
        System.out.println("Result: " + result);
    }

    public void calculatorByStandardEvaluationContext() {
        ExpressionParser parser = new SpelExpressionParser();
        StandardEvaluationContext context = new StandardEvaluationContext();
        context.setVariable("x", 10);
        context.setVariable("y", 5);
        Integer result = parser.parseExpression("#x * #y").getValue(context, Integer.class);

        System.out.println("Result: " + result);
    }

    public void callMethod() {
        ExpressionParser parser = new SpelExpressionParser();
        Expression expression = parser.parseExpression("'hello'.toUpperCase()");
        String result = expression.getValue(String.class);
        System.out.println("Result: " + result);
    }
}
