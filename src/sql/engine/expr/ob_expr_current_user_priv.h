/**
 * Copyright (c) 2021 OceanBase
 * OceanBase CE is licensed under Mulan PubL v2.
 * You can use this software according to the terms and conditions of the Mulan PubL v2.
 * You may obtain a copy of Mulan PubL v2 at:
 *          http://license.coscl.org.cn/MulanPubL-2.0
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PubL v2 for more details.
 */

#ifndef OCEANBASE_SQL_ENGINE_EXPR_OB_EXPR_CURRENT_USER_PRIV_
#define OCEANBASE_SQL_ENGINE_EXPR_OB_EXPR_CURRENT_USER_PRIV_

#include "sql/engine/expr/ob_expr_operator.h"

namespace oceanbase
{
namespace sql
{
class ObExprCurrentUserPriv : public ObFuncExprOperator
{
public:
  explicit  ObExprCurrentUserPriv(common::ObIAllocator &alloc);
  virtual ~ObExprCurrentUserPriv();
  virtual int calc_result_type0(ObExprResType &type,
                                common::ObExprTypeCtx &type_ctx) const;
  static int eval_current_user_priv(const ObExpr &expr, ObEvalCtx &ctx, ObDatum &expr_datum);
  virtual int cg_expr(ObExprCGCtx &op_cg_ctx,
                      const ObRawExpr &raw_expr,
                      ObExpr &rt_expr) const override;
private:
  DISALLOW_COPY_AND_ASSIGN(ObExprCurrentUserPriv);
};

class ObExprCurrentRole : public ObFuncExprOperator
{
public:
  explicit  ObExprCurrentRole(common::ObIAllocator &alloc);
  virtual ~ObExprCurrentRole();
  virtual int calc_result_type0(ObExprResType &type,
                                common::ObExprTypeCtx &type_ctx) const;
  static int eval_current_role(const ObExpr &expr, ObEvalCtx &ctx, ObDatum &expr_datum);
  virtual int cg_expr(ObExprCGCtx &op_cg_ctx,
                      const ObRawExpr &raw_expr,
                      ObExpr &rt_expr) const override;
private:
  DISALLOW_COPY_AND_ASSIGN(ObExprCurrentRole);
};
}
}
#endif /* OCEANBASE_SQL_ENGINE_EXPR_OB_EXPR_CURRENT_USER_PRIV_ */
